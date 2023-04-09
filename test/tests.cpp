#include "gtest/gtest.h"
#include "stack.h"

class StackTest : public ::testing::Test {
protected:
    void SetUp() override {
        stack = stack_create(5);
    }

    void TearDown() override {
        stack_destroy(stack);
    }

    Stack_t* stack;
};

TEST_F(StackTest, EmptyStackTest) {
    EXPECT_EQ(stack_is_empty(stack), 1);
}

TEST_F(StackTest, PushPopTest) {
    int a = 1, b = 2, c = 3;
    stack_push(stack, &a);
    stack_push(stack, &b);
    stack_push(stack, &c);

    EXPECT_EQ(stack_is_empty(stack), 0);

    int *popped_c = (int*) stack_pop(stack);
    EXPECT_EQ(*popped_c, c);

    int *popped_b = (int*) stack_pop(stack);
    EXPECT_EQ(*popped_b, b);

    int *popped_a = (int*) stack_pop(stack);
    EXPECT_EQ(*popped_a, a);

    EXPECT_EQ(stack_is_empty(stack), 1);
}

TEST_F(StackTest, PeekTest) {
    int a = 1, b = 2, c = 3;
    stack_push(stack, &a);
    stack_push(stack, &b);
    stack_push(stack, &c);

    int *peeked_c = (int*) stack_peek(stack);
    EXPECT_EQ(*peeked_c, c);

    int *popped_c = (int*) stack_pop(stack);
    EXPECT_EQ(*popped_c, c);

    int *peeked_b = (int*) stack_peek(stack);
    EXPECT_EQ(*peeked_b, b);
}

TEST_F(StackTest, CreateDestroyTest) {
    Stack_t* new_stack = stack_create(3);

    EXPECT_NE(new_stack, nullptr);

    stack_destroy(new_stack);
}

TEST_F(StackTest, FullStackTest) {
    int data1 = 42, data2 = 84, data3 = 168, data4 = 168, data5 = 168, data6 = 168;
    EXPECT_EQ(stack_push(stack, &data1), 1);
    EXPECT_EQ(stack_push(stack, &data2), 1);
    EXPECT_EQ(stack_push(stack, &data3), 1);
    EXPECT_EQ(stack_push(stack, &data4), 1);
    EXPECT_EQ(stack_push(stack, &data5), 1);
    EXPECT_EQ(stack_push(stack, &data6), 0);
}

TEST_F(StackTest, EmptyStackPopTest) {
    ASSERT_EQ(stack_pop(stack), nullptr);
}

TEST_F(StackTest, EmptyStackPeekTest) {
    ASSERT_EQ(stack_peek(stack), nullptr);
}