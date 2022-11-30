/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, SmokeTest) 
{
	ASSERT_TRUE(true);
}

TEST(tappityTest, LengthTest)
{
	tappityTest game("This is a nice Sentence"); 
	game.entry("This is is a nice Sentence");

	ASSERT_EQ(game.length_difference(), 0);
}