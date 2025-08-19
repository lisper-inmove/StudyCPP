#include <gtest/gtest.h>
#include "math_utils.h"

#include "ilog/logger.h"
#include "ilog/log_format.h"
#include "ilog/log_output.h"
#include "ilog/log_factory.h"

TEST(MathTest, AddPositive1) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(MathTest, AddNegative) {
    EXPECT_EQ(add(-1, -1), -2);
}

TEST(MathTest, Multiply) {
    EXPECT_EQ(mul(3, 4), 12);
}

TEST(LOGGER, Logger)
{
	XMLLogFormat f = XMLLogFormat();
	LogFactory& fac = LogFactory::instance();
	fac.getLogger().setFormat(&f);
	// fac.getLogger().setOutput(new ConsoleLogOutput);
	fac.getLogger().setOutput(new FileLogOutput("log.txt"));
	DEBUG("This is a DEBUG message");
	INFO("This is a INFO message");
	ERROR("This is a ERROR message");
	FATAL("This is a FATAL message");
}