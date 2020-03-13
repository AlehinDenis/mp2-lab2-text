#include <iostream>
#include "List.h"

std::pair<int, std::string>& MyIterator::operator*()
{
	return std::pair<int, std::string>(it->level, it->data);
}

std::pair<int, std::string>& MyIterator::operator->()
{
	return std::pair<int, std::string>(it->next->level, it->next->data);
}

MyIterator MyIterator::next()
{
	it = it->next;
	return *this;
}

MyIterator MyIterator::endNext()
{
	while (it->next != nullptr)
		next();
	return *this;
}

MyIterator MyIterator::nextLevel()
{
	it = it->down;
	return *this;
}

MyIterator MyIterator::endNextLevel()
{
	while (it->down != nullptr)
		nextLevel();
	return *this;
}