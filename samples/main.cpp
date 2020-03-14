#include <iostream>
#include "List.h"

int main()
{
	MyList list;
	MyIterator iterator;
	list.push_back_next_level("1");
	list.push_back_current_level("2");
	list.push_back_next_level("3");
}