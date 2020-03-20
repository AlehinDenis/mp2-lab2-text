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

TEST(MyList, can_get_begin_from_empty_list)
{
	MyList test;

	EXPECT_EQ(nullptr, test.getBegin().it);
}

TEST(MyList, can_get_begin_from_list_with_elements)
{
	MyList test;
	test.push_back_current_level("Test");

	EXPECT_EQ("Test", test.getBegin().it->data);
}

TEST(MyList, can_get_end_from_empty_list)
{
	MyList test;

	EXPECT_EQ(nullptr, test.getEnd().it);
}

TEST(MyList, can_get_end_from_list_with_one_element)
{
	MyList test;
	test.push_back_current_level("Test");

	EXPECT_EQ("Test", test.getEnd().it->data);
}

TEST(MyList, can_get_end_from_list_with_two_elements)
{
	MyList test;
	test.push_back_current_level("Test1");
	test.push_back_current_level("Test2");

	EXPECT_EQ("Test2", test.getEnd().it->data);
}

TEST(MyIterator, can_insertnext_in_current_node_if_it_is_empty)
{
	MyIterator test;
	test.insNext("Test");

	EXPECT_EQ("Test", test.it->data);
	EXPECT_EQ(0, test.it->level);
}

TEST(MyIterator, can_insertdown_in_current_node_if_it_is_empty)
{
	MyIterator test;
	test.insDown("Test");

	EXPECT_EQ("Test", test.it->data);
	EXPECT_EQ(0, test.it->level);
}

TEST(MyList, can_push_back_current_level)
{
	MyList test;
	test.push_back_current_level("Test1");
	test.push_back_current_level("Test2");
	
	EXPECT_EQ("Test1", test.getBegin().it->data);
	EXPECT_EQ("Test2", test.getEnd().it->data);
}

TEST(MyList, can_push_back_next_level)
{
	MyList test;
	test.push_back_next_level("Test1");
	test.push_back_next_level("Test2");

	EXPECT_EQ("Test1", test.getBegin().it->data);
	EXPECT_EQ("Test2", test.getBegin().endNextLevel().it->data);
}
