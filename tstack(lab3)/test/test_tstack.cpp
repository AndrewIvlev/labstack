#include "..\tstack(lab3)\tstack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> s(10));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
   ASSERT_ANY_THROW(TStack<int> s(-10));
}