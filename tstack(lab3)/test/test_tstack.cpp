#include "..\tstack(lab3)\tstack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW( TStack<int> s(9) );
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW( TStack<int> s(-9) );
}

TEST(TStack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW( TStack<int> v(MAX_STACK_SIZE + 1) );
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> s(9);

	ASSERT_NO_THROW( TStack<int> s1(s) );
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> s(5), s1(s);

	EXPECT_NE( &s1 , &s);
}

TEST(TStack, can_clear_stack)
{
	TStack<int> s(9);

	s.Clear();

	EXPECT_EQ( true, s.isempty() );
}

TEST(TStack, can_get_top_of_stack_which_is_not_empty)
{
	TStack<int> s(8);

	s.push(7);

	EXPECT_EQ( 7, s.top() );
}

TEST(TStack, cant_get_top_of_stack_which_is_empty)
{
	TStack<int> s(8);

	s.Clear();

	ASSERT_ANY_THROW( s.top() );
}

TEST(TStack, can_put_element_on_stack_which_is_not_full)
{
	TStack<int> s(8);

	s.push(7);

	EXPECT_EQ( 7, s.top() );
}

TEST(TStack, cant_put_element_on_stack_which_is_full)
{
	TStack<int> s(2);

	s.push(7);
	s.push(7);

	ASSERT_ANY_THROW( s.push(7) );
}

TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> s(5);

	ASSERT_NO_THROW(s = s);
}

TEST(TStack, can_assign_stacks_of_equal_size)
{
	TStack<int> s(5), s1(5);

	ASSERT_NO_THROW(s1 = s);
}

TEST(TStack, can_assign_stacks_of_different_size)
{	
	TStack<int> s(4);
	TStack<int> s1(5);

	ASSERT_NO_THROW(s1 = s);;
}

TEST(TStack, can_throw_top_of_stack_which_is_not_empty)
{
	TStack<int> s(8);

	s.push(7);

	EXPECT_EQ( 7, s.pop() );
}

TEST(TStack, cant_throw_top_of_stack_which_is_empty)
{
	TStack<int> s(8);

	s.Clear();

	ASSERT_ANY_THROW( s.pop() );
}

