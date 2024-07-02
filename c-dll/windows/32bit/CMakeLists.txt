cmake_minimum_required(VERSION 3.6)
project(API_AMC_IDS VERSION 1.0)

###BEGIN GOOGLETEST

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build"
)

####END GOOGLETEST




if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to Release as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE
        STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# This is how we could set compiler options
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-long-long -pedantic -Werror")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDLL_EXPORT")
endif()

set(LIBRARY_SRC net.c cJSON.c generatedAPI.c attocubeJSONCall.c)

if(WIN32)
    list(APPEND LIBS_TO_LINK wsock32 ws2_32)
endif()

STRING(REGEX REPLACE "CRYO" "Dry" productName "$ENV{PROD}")

set(productSuffix "")
if(DEFINED ENV{INTERNAL})
    set(productSuffix "internal")
endif()

add_library(attocubeJSON SHARED ${LIBRARY_SRC})
target_link_libraries(attocubeJSON ${LIBS_TO_LINK})
set_target_properties(attocubeJSON PROPERTIES PREFIX "libatto")
set_target_properties(attocubeJSON PROPERTIES OUTPUT_NAME "${productName}${productSuffix}-$ENV{VERSION}")

set(SOURCE_FILES googleTest_amc.cpp)
add_executable(testdll ${SOURCE_FILES})
target_link_libraries(testdll attocubeJSON gtest gtest_main)
add_test(testdll testdll)

