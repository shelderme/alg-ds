#include "pch.h"
extern"C" {
#include"../Stack/stack.h"
}

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(PushArrayStack, AddingElem) {
    int arr[3];
    ArrayStack_t stek = { arr, 0, 3 };
    PushArrayStack(&stek, 5);
    int b;
    b = stek.data[stek.top - 1];
    ASSERT_EQ(5, b);
}

TEST(PushArrayStack, AddingFewElements) {
    int arr[3] = {2, 3};
    ArrayStack_t stek = { arr, 2, 3 };
    PushArrayStack(&stek, 5);
    int b;
    b = stek.data[stek.top - 1];
    ASSERT_EQ(5, b);
}

TEST(PopArrayStack, PopTest_RetunsLastElem) {
    int arr[3] = { 2, 3, 4 };
    ArrayStack_t stek = { arr, 3, 3 };
  
    int b = PopArrayStack(&stek);
    ASSERT_EQ(4, b);
}

TEST(PopArrayStack, PopTest_UnderflowAttempt) {
    int arr[1] = { 2 };
    ArrayStack_t stek = { arr, 1, 1 };
    int a = PopArrayStack(&stek);
    int b = PopArrayStack(&stek);
    ASSERT_EQ(-3, b);
}

TEST(PushArrayList, AddingElem) {
    ListStack_t *stek = NULL;
    stek = CreateListStack();
    PushListStack(&stek, 23);
    int elem = stek->data;
    ASSERT_EQ(23, elem);
}

TEST(PushListStack, AddingFewElem) {
    ListStack_t* stek = NULL;
    stek = CreateListStack();
    PushListStack(&stek, 23);
    PushListStack(&stek, 433);
    PushListStack(&stek, 54);
    int elem = stek->data;
    ASSERT_EQ(54, elem);
}



TEST(PopListStack, PopPushInteraction_ReturnPushedElement) {
    ListStack_t* stek = CreateListStack();
    ListStack_t* newElem = CreateListStack();
    newElem->data = 1;
    newElem->prev = stek;
    stek = newElem;
    EXPECT_TRUE(PopListStack(&stek) == 1);
    EXPECT_TRUE(stek->prev == NULL);
}

TEST(PushPopListTest, PushAndPop) {
    ListStack_t* stek = CreateLinkedListStack();
    PushListStack(&stek, 1);
    PushListStack(&stek, 2);
    PushListStack(&stek, 3);
    EXPECT_TRUE(PopListStack(&stek) == 3);
    EXPECT_TRUE(PopListStack(&stek) == 2);
    EXPECT_TRUE(stek->prev->prev == NULL);
}
