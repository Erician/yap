#include <limits.h>
#include "gtest/gtest.h"
#include "logging/yap_config.h"
#include "logging/yap_const.h"

class ConfigTest : public ::testing::Test
{
protected:
    virtual void SetUp() {
        config.Init("logging/yap_logging.ini");
    }
    virtual void TearDown() {
        ;
    }
    Config config;
};

TEST_F(ConfigTest, IsHave_ShouldPass)
{
    ASSERT_EQ(true, config.IsHave(yap::config::kLogFilePath));
}

TEST_F(ConfigTest, GetValue_ShouldPass)
{
    ASSERT_EQ("../logs/log.txt", config.GetValue(yap::config::kLogFilePath));
}


