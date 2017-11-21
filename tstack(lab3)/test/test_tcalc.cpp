#include "..\tstack(lab3)\tcalculator.h"

#include "gtest.h"
#include <string>

TEST(TCalc, can_create_tcalc_object)
{
	ASSERT_NO_THROW( TCalc Ñ );
}

TEST(TCalc, can_check_simple_expression_that_is_correct)
{
	TCalc C;
	string s = "56+92*8";

	C.Setinfix(s);

	EXPECT_EQ( true, C.Check() );
}

TEST(TCalc, can_check_simple_expression_that_is_incorrect)
{
	TCalc C;
	string s = "*56+92 8";

	C.Setinfix(s);

	EXPECT_EQ( false, C.Check() );
}