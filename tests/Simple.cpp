#include <gtest/gtest.h>

class Test : public testing::Test
{
public:

};

TEST_F(Test, SimpleTest)
{
	ASSERT_EQ(1,1);
}