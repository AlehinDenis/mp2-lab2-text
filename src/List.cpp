#include <iostream>
#include "List.h"
/*
std::pair<int, std::string> MyIterator::operator*()
{
	return std::pair<int, std::string>(it->level, it->data);
}

std::pair<int, std::string> MyIterator::operator->()
{
	return std::pair<int, std::string>(it->next->level, it->next->data);
}*/

MyIterator MyIterator::next()
{
	if (it->next == nullptr)
		throw "Can't go right";
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
	if (it->down == nullptr)
		throw "Can't go nextLevel";
	it = it->down;
	return *this;
}

MyIterator MyIterator::endNextLevel()
{
	while (it->down != nullptr)
		nextLevel();
	return *this;
}

void MyIterator::insNext(std::string data)
{
	int lev = it->level;
	it->next = new Node(data, lev);
}

void MyIterator::insDown(std::string data)
{
	int lev = it->level;
	it->down = new Node(data, lev + 1);
}

bool MyIterator::operator==(const MyIterator& iterator)
{
	if (this->it->data == iterator.it->data && this->it->level == iterator.it->level)
		return true;
	return false;
}

bool MyIterator::operator!=(const MyIterator& iterator)
{
	if (this->it->data != iterator.it->data || this->it->level != iterator.it->level)
		return true;
	return false;
}
