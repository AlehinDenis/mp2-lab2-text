#include <gtest.h>

#include "List.h"


TEST(MyIterator, can_be_created)
{

	ASSERT_NO_THROW(MyIterator iterator);
}

TEST(MyIterator, can_go_right_without_exceptions)
{
	MyIterator iterator;
	iterator.it = new Node;
	iterator.insNext("Data");

	ASSERT_NO_THROW(iterator.next());
}

TEST(MyIterator, can_go_right)
{
	MyIterator iterator;
	iterator.it = new Node;
	iterator.insNext("Data");
	Node* temp = iterator.it->next;

	EXPECT_EQ(temp, iterator.next().it);
}

TEST(MyIterator, cant_go_right_if_next_equal_nullptr)
{
	MyIterator iterator;
	iterator.it = new Node;

	ASSERT_ANY_THROW(iterator.next());
}

TEST(MyIterator, can_insert_next)
{
	MyIterator iterator;
	iterator.it = new Node;
	int curLev = iterator.it->level;
	iterator.insNext("Data");
	iterator.next();

	EXPECT_EQ("Data", iterator.it->data);
	EXPECT_EQ(curLev, iterator.it->level);
}

TEST(MyIterator, can_go_nextLevel_without_exceptions)
{
	MyIterator iterator;
	iterator.it = new Node;
	iterator.insDown("Data");

	ASSERT_NO_THROW(iterator.nextLevel());
}

TEST(MyIterator, can_go_nextLevel)
{
	MyIterator iterator;
	iterator.it = new Node;
	iterator.insDown("Data");
	Node* temp = iterator.it->down;

	EXPECT_EQ(temp, iterator.nextLevel().it);
}

TEST(MyIterator, cant_go_right_if_nextLevel_equal_nullptr)
{
	MyIterator iterator;
	iterator.it = new Node;

	ASSERT_ANY_THROW(iterator.nextLevel());
}

TEST(MyIterator, can_insert_nextLevel)
{
	MyIterator iterator;
	iterator.it = new Node;
	int curLev = iterator.it->level;
	iterator.insDown("Data");
	iterator.nextLevel();

	EXPECT_EQ("Data", iterator.it->data);
	EXPECT_EQ(curLev + 1, iterator.it->level);
}

TEST(MyIterator, can_go_to_the_end)
{
	MyIterator iterator;
	iterator.it = new Node;
	iterator.insNext("1"); 
	iterator.it->next->next = new Node("2");

	EXPECT_EQ("2", iterator.endNext().it->data);
}

TEST(MyIterator, can_go_to_the_nextLevel_end)
{
	MyIterator iterator;
	iterator.it = new Node;
	iterator.insDown("1");
	iterator.it->down->down = new Node("2");

	EXPECT_EQ("2", iterator.endNextLevel().it->data);
}

TEST(MyIterator, can_compare_two_equal_MyIterator)
{
	MyIterator iterator1;
	MyIterator iterator2;
	iterator1.it = new Node("Data");
	iterator2.it = new Node("Data");

	EXPECT_EQ(true, iterator1 == iterator2);
	EXPECT_EQ(false, iterator1 != iterator2);
}

TEST(MyIterator, can_compare_two_not_equal_MyIterator)
{
	MyIterator iterator1;
	MyIterator iterator2;
	iterator1.it = new Node("Data1");
	iterator2.it = new Node("Data2");

	EXPECT_EQ(false, iterator1 == iterator2);
	EXPECT_EQ(true, iterator1 != iterator2);
}
