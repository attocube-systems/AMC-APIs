#include <iostream>


#include <gtest/gtest.h>

#include "generatedAPI.h"
#include "attocubeJSONCall.h"

int deviceHandle;
int axis = 1;
//const char* device = "10.99.70.225";
const char* device = "127.0.0.1";


class AttoTest : public ::testing::Test {
    protected:
        void SetUp() override {
            Connect(device, &deviceHandle);
        }

        void TearDown() override {
            Disconnect(deviceHandle);
        }

};

TEST_F(AttoTest, AMC_control_getActorNameTest)
{
    char val[100];
    const char* expect_val = "ANPx101";
    int retVal = AMC_control_getActorName(deviceHandle, axis, val, sizeof(val));
    ASSERT_STREQ(expect_val, val);
}
TEST_F(AttoTest, AMC_control_getActorName_errNoTest)
{
    char val[100];
    int expect_val = 7; // eigenheit simulator auf device 6

    int retVal = AMC_control_getActorName(deviceHandle, 8, val, sizeof(val));
    ASSERT_EQ(expect_val, retVal);
}
TEST_F(AttoTest, AMC_control_setSensorEnabledTest)
{
    int exp_val = 0;
    int retVal = AMC_control_setSensorEnabled(deviceHandle, axis, true);
    ASSERT_EQ(exp_val, retVal);
}

TEST_F(AttoTest, AMC_move_getControlTargetPositionTest)
{
    double position;
    int retVal = AMC_move_getControlTargetPosition(deviceHandle, axis, &position);
    EXPECT_DOUBLE_EQ(100000, position);
}

TEST_F(AttoTest, AMC_move_setControlTargetPositionTest)
{
    double target = 1;
    int exp_val = 0;
    int retVal = AMC_move_setControlTargetPosition(deviceHandle, axis, target);
    ASSERT_EQ(exp_val, retVal);
}
TEST_F(AttoTest, AMC_move_getControlEotOutputDeactiveTest)
{
    bool value_boolean1;
    int exp_val = 0;
    int retVal = AMC_move_getControlEotOutputDeactive(deviceHandle, axis, &value_boolean1);
    ASSERT_FALSE(retVal);
}

/*
   TEST_F(AttoTest, AMC_rtin_getRealTimeInChangePerPulseTest)

   {
   int val;
   int expect_val = 0;
   int retVal = AMC_rtin_getRealTimeInChangePerPulse(deviceHandle, 1, 1, val);
   ASSERT_EQ(expect_val, val);
   }
   */



