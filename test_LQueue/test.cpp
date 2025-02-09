#include "pch.h"
#include "../LQueue/LQueue.h"

TEST(LQueue, Correct_IsEmpty_Initially) {
    LQueue<int> q1;
    EXPECT_EQ(1, q1.IsEmpty()); // Очередь должна быть пустой сразу после создания
}

TEST(LQueue, Correct_IsEmpty_AfterPush) {
    LQueue<int> q1;
    q1.Push(1);
    EXPECT_EQ(0, q1.IsEmpty()); // Очередь не должна быть пустой после добавления элемента
}

TEST(LQueue, Correct_Push) {
    LQueue<int> q1;
    q1.Push(42);
    EXPECT_EQ(42, q1.PeekTail()); // Проверяем, что элемент добавлен в конец
}

TEST(LQueue, Correct_Pop) {
    LQueue<int> q1;
    q1.Push(10);
    EXPECT_EQ(10, q1.Pop()); // Проверяем, что pop возвращает правильное значение
}

TEST(LQueue, Correct_Push_Pop_Sequence) {
    LQueue<int> q1;
    for (int i = 0; i < 5; i++) {
        q1.Push(i);
    }
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(i, q1.Pop()); // Проверяем, что элементы выходят в правильном порядке
    }
}

TEST(LQueue, Correct_PeekHead) {
    LQueue<int> q1;
    q1.Push(0);
    for (int i = 1; i < 5; i++) {
        q1.Push(i);
        EXPECT_EQ(0, q1.PeekHead()); // Голова очереди не меняется
    }
}

TEST(LQueue, Correct_PeekTail) {
    LQueue<int> q1;
    for (int i = 0; i < 5; i++) {
        q1.Push(i);
        EXPECT_EQ(i, q1.PeekTail()); // Хвост должен совпадать с последним добавленным элементом
    }
}

TEST(LQueue, Correct_Equal_True) {
    LQueue<int> q1, q2;
    for (int i = 0; i < 5; i++) {
        q1.Push(i);
        q2.Push(i);
    }
    EXPECT_EQ(q1, q2); // Две одинаковые очереди должны быть равны
}

TEST(LQueue, Correct_Equal_False) {
    LQueue<int> q1, q2;
    for (int i = 0; i < 5; i++) {
        q1.Push(i);
        q2.Push(i);
    }
    q1.Pop();
    EXPECT_NE(q1, q2); // Очереди с разными элементами должны быть не равны
}

TEST(LQueue, Correct_Assignment_Copy) {
    LQueue<int> q1, q2;
    for (int i = 0; i < 5; i++) {
        q1.Push(i);
    }
    q2 = q1;
    EXPECT_EQ(q1, q2); // Проверяем, что после присваивания очереди равны
}

TEST(LQueue, Correct_Assignment_Independent) {
    LQueue<int> q1, q2;
    for (int i = 0; i < 5; i++) {
        q1.Push(i);
    }
    q2 = q1;
    q1.Pop();
    EXPECT_NE(q1, q2); // Проверяем, что очереди независимы после присваивания
}


