#include "LinkedList.h"
#include <gtest/gtest.h>
using namespace std;
using namespace List;
TEST(LinkedListTests, Push_tail_item)
{
    LinkedList<int> l;
    l.push_tail(3);
    l.push_tail(5);
    l.push_tail(7);
    EXPECT_EQ(l.size(), 3);
    EXPECT_EQ(l[0], 3);
    EXPECT_EQ(l[1], 5);
    EXPECT_EQ(l[2], 7);
}
TEST(LinkedListTests, Construct_copy)
{
    LinkedList<int> l;
    l.push_tail(3);
    l.push_tail(5);
    l.push_tail(7);
    LinkedList<int> l2(l);
    EXPECT_EQ(l2.size(), 3);
    EXPECT_EQ(l2[0], 3);
    EXPECT_EQ(l2[1], 5);
    EXPECT_EQ(l2[2], 7);
}
TEST(LinkedListTests, Assignment_operation)
{
    LinkedList<int> l;
    l.push_tail(3);
    l.push_tail(5);
    l.push_tail(7);
    LinkedList<int> l2 =l;
    EXPECT_EQ(l2.size(), 3);
    EXPECT_EQ(l2[0], 3);
    EXPECT_EQ(l2[1], 5);
    EXPECT_EQ(l2[2], 7);
}
TEST(LinkedListTests, Assignment_by_index)
{
    LinkedList<int> l;
    l.push_tail(3);
    l.push_tail(5);
    l.push_tail(7);
    l[0] = 1;
    l[1] = 2;
    l[2] = 3;
    EXPECT_EQ(l.size(), 3);
    EXPECT_EQ(l[0], 1);
    EXPECT_EQ(l[1], 2);
    EXPECT_EQ(l[2], 3);
}
TEST(LinkedListTests, Push_tail_list)
{
    LinkedList<int> l;
    l.push_tail(3);
    l.push_tail(5);
    l.push_tail(7);

    LinkedList<int> l2;
    l2.push_tail(4);
    l2.push_tail(6);
    l2.push_tail(8);
    l.push_tail(l2);
    EXPECT_EQ(l.size(), 6);
    EXPECT_EQ(l[0], 3);
    EXPECT_EQ(l[1], 5);
    EXPECT_EQ(l[2], 7);
    EXPECT_EQ(l[3], 4);
    EXPECT_EQ(l[4], 6);
    EXPECT_EQ(l[5], 8);
}
TEST(LinkedListTests, Push_head_item)
{
    LinkedList<int> l;
    l.push_head(3);
    l.push_head(5);
    l.push_head(7);
    EXPECT_EQ(l.size(), 3);
    EXPECT_EQ(l[0], 7);
    EXPECT_EQ(l[1], 5);
    EXPECT_EQ(l[2], 3);
}
TEST(LinkedListTests, Push_head_list)
{
    LinkedList<int> l;
    l.push_tail(4);
    l.push_tail(5);
    l.push_tail(6);

    LinkedList<int> l2;
    l2.push_tail(1);
    l2.push_tail(2);
    l2.push_tail(3);
    l.push_head(l2);

    EXPECT_EQ(l.size(), 6);
    EXPECT_EQ(l[0], 1);
    EXPECT_EQ(l[1], 2);
    EXPECT_EQ(l[2], 3);
    EXPECT_EQ(l[3], 4);
    EXPECT_EQ(l[4], 5);
    EXPECT_EQ(l[5], 6);
}
TEST(LinkedListTests, Pop_tail)
{
    LinkedList<int> l;
    l.push_tail(1);
    l.push_tail(2);
    l.push_tail(3);

    l.pop_tail();

    EXPECT_EQ(l.size(), 2);
    EXPECT_EQ(l[0], 1);
    EXPECT_EQ(l[1], 2);
}
TEST(LinkedListTests, Pop_head)
{
    LinkedList<int> l;
    l.push_tail(1);
    l.push_tail(2);
    l.push_tail(3);

    l.pop_head();

    EXPECT_EQ(l.size(), 2);
    EXPECT_EQ(l[0], 2);
    EXPECT_EQ(l[1], 3);

}
TEST(LinkedListTests, Delete_node)
{
    LinkedList<int> l;
    l.push_tail(1);
    l.push_tail(1);
    l.push_tail(2);
    l.push_tail(1);
    l.push_tail(1);
    l.push_tail(2);

    l.delete_node(1);

    EXPECT_EQ(l.size(), 2);
    EXPECT_EQ(l[0], 2);
    EXPECT_EQ(l[1], 2);

}
