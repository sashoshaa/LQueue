#include "pch.h"
#include "../LQueue/LQueue.h"

TEST(LQueue, Correct_IsEmpty_Initially) {
    LQueue<int> q1;
    EXPECT_EQ(1, q1.IsEmpty()); // ������� ������ ���� ������ ����� ����� ��������
}

TEST(LQueue, Correct_IsEmpty_AfterPush) {
    LQueue<int> q1;
    q1.Push(1);
    EXPECT_EQ(0, q1.IsEmpty()); // ������� �� ������ ���� ������ ����� ���������� ��������
}

TEST(LQueue, Correct_Push) {
    LQueue<int> q1;
    q1.Push(42);
    EXPECT_EQ(42, q1.PeekTail()); // ���������, ��� ������� �������� � �����
}

TEST(LQueue, Correct_Pop) {
    LQueue<int> q1;
    q1.Push(10);
    EXPECT_EQ(10, q1.Pop()); // ���������, ��� pop ���������� ���������� ��������
}

TEST(LQueue, Correct_Push_Pop_Sequence) {
    LQueue<int> q1;
    for (int i = 0; i < 5; i++) {
        q1.Push(i);
    }
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(i, q1.Pop()); // ���������, ��� �������� ������� � ���������� �������
    }
}

TEST(LQueue, Correct_PeekHead) {
    LQueue<int> q1;
    q1.Push(0);
    for (int i = 1; i < 5; i++) {
        q1.Push(i);
        EXPECT_EQ(0, q1.PeekHead()); // ������ ������� �� ��������
    }
}

TEST(LQueue, Correct_PeekTail) {
    LQueue<int> q1;
    for (int i = 0; i < 5; i++) {
        q1.Push(i);
        EXPECT_EQ(i, q1.PeekTail()); // ����� ������ ��������� � ��������� ����������� ���������
    }
}

TEST(LQueue, Correct_Equal_True) {
    LQueue<int> q1, q2;
    for (int i = 0; i < 5; i++) {
        q1.Push(i);
        q2.Push(i);
    }
    EXPECT_EQ(q1, q2); // ��� ���������� ������� ������ ���� �����
}

TEST(LQueue, Correct_Equal_False) {
    LQueue<int> q1, q2;
    for (int i = 0; i < 5; i++) {
        q1.Push(i);
        q2.Push(i);
    }
    q1.Pop();
    EXPECT_NE(q1, q2); // ������� � ������� ���������� ������ ���� �� �����
}

TEST(LQueue, Correct_Assignment_Copy) {
    LQueue<int> q1, q2;
    for (int i = 0; i < 5; i++) {
        q1.Push(i);
    }
    q2 = q1;
    EXPECT_EQ(q1, q2); // ���������, ��� ����� ������������ ������� �����
}

TEST(LQueue, Correct_Assignment_Independent) {
    LQueue<int> q1, q2;
    for (int i = 0; i < 5; i++) {
        q1.Push(i);
    }
    q2 = q1;
    q1.Pop();
    EXPECT_NE(q1, q2); // ���������, ��� ������� ���������� ����� ������������
}


