/**
  Copyright (C) 2020 attocube systems AG

  Usage is up to a separate agreement
  */

/**
 * @file attocubeJSONCall.c
 * @author MSa
 * @date 2020.04.17
 * @brief RPC file with the attocube devices
 *
 * This implementation file contains the device connector
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "attocubeJSONCall.h"

#ifndef __WINDOWS__
#include <arpa/inet.h>
#else
#include <winsock2.h>
#include <Ws2tcpip.h>
#endif


#include "cJSON.h"
#include "net.h"


int ATTOCUBE_API Connect(const char *deviceAddress, int* deviceHandle)
{
    net_init();
    struct in_addr address;

    if (inet_pton(AF_INET, deviceAddress, &address) <= 0)
    {
        fprintf(stderr, "Can not convert address\n");
        return ATTOCUBE_InvalidParam;
    }
    *deviceHandle = net_connect(address);
    if (*deviceHandle <= 0)
    {
        int retval = *deviceHandle;
        *deviceHandle = -1;
        return retval;
    }

    return ATTOCUBE_Ok;
}

int ATTOCUBE_API setPort(int port)
{
    net_set_port(port);
    return 0;
}


int ATTOCUBE_API Disconnect(int deviceHandle )
{
    net_disconnect(deviceHandle);
    return 0;
}


static int callRemote(int deviceHandle, const char * method, cJSON * params, cJSON** response)
{
    static int id = 0;
    cJSON *root;
    root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "jsonrpc", "2.0");
    cJSON_AddStringToObject(root, "method", method);
    if(params)
        cJSON_AddItemToObject(root, "params", params);
    cJSON_AddNumberToObject(root, "id", id);
    cJSON_AddNumberToObject(root, "api", 2);
    id++;
    char * text = cJSON_Print(root);
    cJSON_Delete(root);

#ifdef DEBUG
    printf("%s\n", text);
#endif

    // Call remote method
    int ret = net_write_server(deviceHandle, text);
    free(text);
    if (ret != 0)
        return ATTOCUBE_NetworkError;

    // read response
    char buffer[1024];
    ret = net_read_server(deviceHandle, buffer, sizeof(buffer));
    if (ret < 0)
        return ATTOCUBE_NetworkError;
#ifdef DEBUG
    printf("Response : \n %s \n", buffer);
#endif

    root = cJSON_Parse(buffer);
    ret = ATTOCUBE_Error;
    if (cJSON_HasObjectItem(root, "result")) {
        *response = cJSON_DetachItemFromObject(root, "result");
        ret = 0;
    }
    else if (cJSON_HasObjectItem(root, "error")) {
        *response = cJSON_DetachItemFromObject(root, "error");
    }

    cJSON_Delete(root);
    return ret;

}


#define MIN(a,b) (((a)<(b))?(a):(b))

/** \brief : Processes the cJSON representation to predefined memory blocks
 *
 * \param[in]   array : Filled cJSON array
 * \param[in]   inputValues : Description of the varargs
 * \param[in]   args : Vararg list containing the memory blocks
 *
 * \return : ATTOCUBE_Ok if success,
 *           The according error in case of failure
 */
static int processJSONArray(cJSON *array, const char* inputValues, va_list* args)
{
    int size = cJSON_GetArraySize(array);
    int i;

    char* stringInput;
    int* intInput;
    double* doubleInput;
    int* intArrayInput;
    double* doubleArrayInput;
    unsigned int maxArrayLength;

    // Loop over the cJSON array to fill the memory blocks
    for (i = 0; i < size; i++, inputValues++)
    {
        if (*inputValues == '\0')
        {
            fprintf(stderr, "Less parameters specified than returned!\n");
            return ATTOCUBE_InvalidParam;
        }

        cJSON* item = cJSON_GetArrayItem(array, i);
        if (item->type == cJSON_Number)
        {
            if (*inputValues == 'n' || *inputValues == 'q' || *inputValues == 'i' || *inputValues == 'u' || *inputValues == 'b')
            {
                intInput = va_arg(*args, int*);
                //printf("Int response: %d\n", item->valueint);
                *intInput = item->valueint;
            }
            else if (*inputValues == 'd')
            {
                doubleInput = va_arg(*args, double*);
                //printf("Double response: %f\n", item->valuedouble);
                *doubleInput = item->valuedouble;
            }
            else
            {
                fprintf(stderr, "Response and parameter list don't match: %c should be an integer type!\n", *inputValues);
                return ATTOCUBE_InvalidParam;
            }
        }
        else if (item->type == cJSON_False) {
            if (*inputValues == 'b')
            {
                intInput = va_arg(*args, int*);
                *intInput = 0;
            }
            else
            {
                fprintf(stderr, "Response and parameter list don't match: %c should be a boolean type!\n", *inputValues);
                return ATTOCUBE_InvalidParam;
            }
        }
        else if (item->type == cJSON_True) {
            if (*inputValues == 'b')
            {
                intInput = va_arg(*args, int*);
                *intInput = 1;
            }
            else
            {
                fprintf(stderr, "Response and parameter list don't match: %c should be a boolean type!\n", *inputValues);
                return ATTOCUBE_InvalidParam;
            }
        }
        else if (item->type == cJSON_String)
        {
            if (*inputValues == 's')
            {
                stringInput = va_arg(*args, char*);
                maxArrayLength = va_arg(*args, unsigned int);
                //printf("String response: %s to max buffer: %d\n", item->valuestring, maxArrayLength);
                snprintf(stringInput, maxArrayLength, "%s", item->valuestring);
            }
            else
            {
                fprintf(stderr, "Response and parameter list don't match: %c should be 's'!\n", *inputValues);
                return ATTOCUBE_InvalidParam;
            }
        }
        else if (item->type == cJSON_Array)
        {
            if (*inputValues == 'a')
            {
                inputValues++;
                if (*inputValues == 'i' || *inputValues == 'u')
                {
                    intArrayInput = va_arg(*args, int*);
                    maxArrayLength = va_arg(*args, unsigned int);

                    int	arraySize = MIN(cJSON_GetArraySize(item), maxArrayLength);
                    int j;
                    // Here we have to cycle over the array ourselves because cJSON doesn't automatically fill it for us
                    for (j = 0; j < arraySize; j++)
                    {
                        cJSON *arrayItem = cJSON_GetArrayItem(item, j);
                        if (arrayItem->type == cJSON_Number)
                        {
                            //printf("Int array response: %d at positon %d\n", item->valueint, j);
                            intArrayInput[j] = item->valueint;
                        }
                        else
                        {
                            fprintf(stderr, "Array response and parameter list don't match: %d should be an integer type!\n", arrayItem->type);
                            return ATTOCUBE_InvalidParam;
                        }
                    }
                }
                else if (*inputValues == 'd')
                {
                    doubleArrayInput = va_arg(*args, double*);
                    maxArrayLength = va_arg(*args, unsigned int);

                    int	arraySize = MIN(cJSON_GetArraySize(item), maxArrayLength);
                    int j;
                    // Here we have to cycle over the array ourselves because cJSON doesn't automatically fill it for us
                    for (j = 0; j < arraySize; j++)
                    {
                        cJSON *arrayItem = cJSON_GetArrayItem(item, j);
                        if (arrayItem->type == cJSON_Number)
                        {
                            //printf("Int array response: %f at positon %d\n", item->valuedouble, j);
                            doubleArrayInput[j] = item->valuedouble;
                        }
                        else
                        {
                            fprintf(stderr, "Array response and parameter list don't match: %d should be double!\n", arrayItem->type);
                            return ATTOCUBE_InvalidParam;
                        }
                    }
                }
                else
                {
                    fprintf(stderr, "Only int and double array types supported. Type is: %c\n", *inputValues);
                    return ATTOCUBE_InvalidParam;
                }
            }
            else
            {
                fprintf(stderr, "Response and parameter list don't match: %c should be 'a'!\n", *inputValues);
                return ATTOCUBE_InvalidParam;
            }
        }
    }

    if (*inputValues != '\0')
    {
        fprintf(stderr, "Warning. More parameters specified than returned!\n");
    }

    return ATTOCUBE_Ok;
}


/** \brief : Makes a cJSON representation of the varargs input parameters
 *
 * \param[in]   inputObject : Parent to put the created children into
 * \param[in]   inputValues : Description of the varargs
 * \param[in]   args : Vararg list of the input parameters
 *
 * \return : ATTOCUBE_Ok if success,
 *           The according error in case of failure
 */
static int processInputParameters(cJSON *inputObject, const char* inputValues, va_list* args)
{
    // Loop over the input paramters to create the cJSON objects
    while (*inputValues != '\0')
    {
        cJSON *inputItem = 0;

        char* stringInput;
        int intInput;
        unsigned int unsignedIntInput;
        double doubleInput;
        int boolInput;
        void* arrayInput;
        char buffer2Bytes[2];
        switch(*inputValues)
        {
            // Array
            case 'a' :
                // We support only arrays of some basic types currently
                inputValues++;
                buffer2Bytes[0] = *inputValues;
                buffer2Bytes[1] = '\0';
                //printf("Input parameter array of: %s\n", buffer2Bytes);

                arrayInput = va_arg(*args, void*);
                int arraySize = va_arg(*args, int);

                //printf("Array size %d\n", arraySize);
                if (*inputValues == 'i' || *inputValues == 'u')
                {
                    // Luckily cJSON creates its arrays from c arrays directly
                    inputItem = cJSON_CreateIntArray((int*)arrayInput, arraySize);
                }
                else if (*inputValues == 'd')
                {
                    // Luckily cJSON creates its arrays from c arrays directly
                    inputItem = cJSON_CreateDoubleArray((double*)arrayInput, arraySize);
                }
                else
                {
                    fprintf(stderr, "Unknown type %c\n", buffer2Bytes[0]);
                    return ATTOCUBE_Error;
                }
                break;
            case 'n' :
                intInput = va_arg(*args, int);
                //printf("Input parameter int16: %d\n",    intInput);
                inputItem = cJSON_CreateNumber(intInput);
                break;
            case 'q' :
                unsignedIntInput = va_arg(*args, unsigned int);
                //printf("Input parameter uint16: %u\n",   unsignedIntInput);
                inputItem = cJSON_CreateNumber(unsignedIntInput);
                break;
            case 'i' :
                intInput = va_arg(*args, int);
                //printf("Input parameter int32: %d\n",    intInput);
                inputItem = cJSON_CreateNumber(intInput);
                break;
            case 'u' :
                unsignedIntInput = va_arg(*args, unsigned int);
                //printf("Input parameter uint32: %u\n",   unsignedIntInput);
                inputItem = cJSON_CreateNumber(unsignedIntInput);
                break;
                /* The cJSON API doesn't support 64 bit ints
                   case 'x' :
                   longLongIntInput = va_arg(*args, long long int);
                   printf("Input parameter int64: %lld\n",  longLongIntInput);
                   inputItem = cJSON_CreateIntArray(&longLongIntInput, 1);
                   break;
                   case 't' :
                   unsignedLongLongIntInput = va_arg(*args, unsigned long long int);
                   printf("Input parameter uint64: %llu\n", unsignedLongLongIntInput);
                   inputItem = cJSON_CreateIntArray(&unsignedLongLongIntInput, 1);
                   break;
                   */
            case 'd' :
                doubleInput = va_arg(*args, double);
                //printf("Input parameter double: %f\n",   doubleInput);
                inputItem = cJSON_CreateNumber(doubleInput);
                break;
            case 'y' :
                intInput = va_arg(*args, int);
                //printf("Input parameter byte: %d\n",     intInput);
                inputItem = cJSON_CreateNumber(intInput);
                break;
            case 's' :
                stringInput = va_arg(*args, char*);
                //printf("Input parameter string: %s\n",   stringInput);
                inputItem = cJSON_CreateString(stringInput);
                break;
            case 'b' :
                boolInput = va_arg(*args, int);
                //printf("Input parameter boolean: %d\n",  boolInput);
                inputItem = cJSON_CreateBool(boolInput);
                break;
            default:
                fprintf(stderr, "Unknown type: %c\n",    (char)*inputValues);
                return -1;
        }
        cJSON_AddItemToArray(inputObject, inputItem);
        inputValues++;
    }

    return ATTOCUBE_Ok;
}


int callRemoteJSONInterface(int deviceHandle, const char* interfaceName, const char* inputValues, const char* outputValues, ...)
{
    if (!interfaceName || !inputValues || !outputValues)
    {
        return ATTOCUBE_Error;
    }

    va_list args;
    // Parse the inputValues
    // The va_start macro enables access to the variable arguments following the named argument outputValues
    va_start(args, outputValues);

    cJSON *inputObject = cJSON_CreateArray();

    // Makes a cJSON representation of the varargs input parameters
    int ret = processInputParameters(inputObject, inputValues, &args);
    if (ret != 0)
    {
        fprintf(stderr, "Can't process input parameters with error %d\n", ret);
        cJSON_Delete(inputObject);
        return ret;
    }


    char *generatedJSONString = cJSON_Print(inputObject);
    if (!generatedJSONString)
    {
        fprintf(stderr, "Can't generate JSON!\n");
        cJSON_Delete(inputObject);
        return ATTOCUBE_Error;
    }

#ifdef DEBUG
    printf("Generated query JSON: %s\n", generatedJSONString);
#endif

    cJSON * response; //json response from server
    int retVal = callRemote(deviceHandle, interfaceName, inputObject, &response);

    if (retVal != ATTOCUBE_Ok)
    {
        printf("Remote call %s returns: %d and response type %d\n", generatedJSONString, retVal, response->type);
        return retVal;
    }

    // Now process the output of the method call
    // Processes the cJSON representation to predefined memory blocks
    ret = processJSONArray(response, outputValues, &args);

    //cJSON_Delete(inputObject); // This is done by callRemote
    cJSON_Delete(response);
    return ret;
}

