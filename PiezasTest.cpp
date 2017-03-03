/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

Piezas p;

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, dropPiece_Col_Less_Than_0)
{
	ASSERT_EQ(p.dropPiece(-1), Invalid);
}

TEST(PiezasTest, dropPiece_Col_0)
{
	ASSERT_EQ(p.dropPiece(0), O);
}

TEST(PiezasTest, dropPiece_Col_Greater_Than_4)
{
	ASSERT_EQ(p.dropPiece(4), Invalid);
}

TEST(PiezasTest, dropPiece_Col_0_Row_1)
{
	ASSERT_EQ(p.dropPiece(0), O);
}

TEST(PiezasTest, dropPiece_Col_0_Row_2)
{
	ASSERT_EQ(p.dropPiece(0), X);
}

TEST(PiezasTest, dropPiece_Col_5)
{
	ASSERT_EQ(p.dropPiece(0), Invalid);
}

TEST(PiezasTest, dropPiece_Col_1_Row_0)
{
	ASSERT_EQ(p.dropPiece(1), X);
}


