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

TEST(MyIterator, can_return_pair_by_operator_of_dereferencing)
{
	MyIterator iterator;
	iterator.it = new Node("Data");
	std::pair<int, std::string> temp(0, "Data");
	std::pair<int, std::string> temp2 = *iterator;

	EXPECT_EQ(temp ,temp2);
}


/*
TEST(MyList, can_create_MyList)
{

	ASSERT_NO_THROW(MyList test);
}

TEST(MyList, can_push_element_to_current_level_without_exceptions)
{
	MyList test;

	ASSERT_NO_THROW(test.push_back_current_level("Test"));
}*/
