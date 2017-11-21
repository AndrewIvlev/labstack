#include "..\tstack(lab3)\tcalculator.cpp"

#include "gtest.h"

TEST(TCalc, can_create_tcalc_object)
{
	ASSERT_NO_THROW( TCalc Ñ );
}

TEST(TCalc, can_add_two_positive_numbers)
{
	TCalc C;

	C.Setinfix("2+2");
	C.topostfix();

	EXPECT_EQ( 4, C.calc() );
}

TEST(TCalc, can_add_two_negative_numbers)
{
	TCalc C;

	C.Setinfix("-2-2");
	C.topostfix();

	EXPECT_EQ( -4, C.calc() );
}

TEST(TCalc, can_multiply_two_numbers)
{
	TCalc C;

	C.Setinfix("4*4");
	C.topostfix();

	EXPECT_EQ( 16, C.calc() );
}

TEST(TCalc, check_expression_that_is_correct)
{
	TCalc C;

	C.Setinfix("56+92*8/2");

	EXPECT_EQ( true, C.Check() );
}

TEST(TCalc, check_expression_that_is_incorrect)
{
	TCalc C;

	C.Setinfix(")56+92*8(");

	EXPECT_EQ( false, C.Check() );
}
 
TEST(TCalc, can_divide_numbers)
{
	TCalc C;

	C.Setinfix("4/4/100");
	C.topostfix();

	EXPECT_EQ( 0.01, C.calc() );
}

TEST(TCalc, expression_is_prioritized)
{
	TCalc C;

	C.Setinfix("1+2-3*4/4");
	C.topostfix();

	EXPECT_EQ( 0, C.calc() );
}