/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
#include <string>

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

TEST(tappityTest, SameLength)
{
	tappity game("This is a nice Sentence"); 
	game.entry("This is a nice Sentence");

	ASSERT_EQ(game.length_difference(), 0);
}

TEST(tappityTest, emptyStrings)
{
	tappity game(""); 
	game.entry("");

	ASSERT_EQ(game.length_difference(), 0);
}

TEST(tappityTest, referenceIsBigger)
{
	tappity game("copy me!");
	game.entry("Nah");

	ASSERT_EQ(game.length_difference(), 5);
}

TEST(tappityTest, referenceIsSmaller)
{
	tappity game("copy me!");
	game.entry("Sure, I will copy you!");

	ASSERT_EQ(game.length_difference(), 14);
}

TEST(tappityTest, wordsAndNumbers)
{
	tappity game("I have 3 Projects that are due on finals week on 12/12/2022");
	game.entry("I have only 5 projects");

	ASSERT_EQ(game.length_difference(), 37);
}

TEST(tappityTest, wordsWithEscapeCharacter)
{
	tappity game("I can create another sentence\n");
	game.entry("Hey me too\nthat's cool");

	ASSERT_EQ(game.length_difference(), 8);
}

TEST(tappityTest, allCorrect)
{
	tappity game("The Big Brown Fox Jumped Over The Fence");
	game.entry("The Big Brown Fox Jumped Over The Fence");

	ASSERT_EQ(game.accuracy(), double(100));
}

TEST(tappityTest, noneCorrect)
{
	tappity game("The Big Brown Fox Jumped Over The Fence");
	game.entry("");

	ASSERT_EQ(game.accuracy(), double(0));
}

TEST(tappityTest, bothEmptyString)
{
	tappity game("");
	game.entry("");

	ASSERT_EQ(game.accuracy(), double(100));
}

TEST(tappityTest, oneIncorrectRefIsBigger)
{
	tappity game("Hello World!");
	game.entry("Hello World");

	ASSERT_EQ(game.accuracy(), double(11/12));
}

TEST(tappityTest, oneIncorrectRefIsSmaller)
{
	tappity game("Hello World!");
	game.entry("Hello World!!");

	ASSERT_EQ(game.accuracy(), double(12/12));
}

TEST(tappityTest, multipleIncorrectSameLength)
{
	tappity game("Hi, I am typing on a mouse");
	game.entry("hi, i im tyeinf no a mouge");

	ASSERT_EQ(game.accuracy(), double(18/26));
}

TEST(tappityTest, multipleIncorrectRefIsBigger)
{
	tappity game("This Dr. Pepper is great!");
	game.entry("thisDr.Perreridgreat!");

	ASSERT_EQ(game.accuracy(), double(3/25));
}