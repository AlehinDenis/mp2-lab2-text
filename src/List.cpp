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

MyIterator MyList::getBegin()
{
	MyIterator temp;
	temp.it = begin;
	return temp;
}

MyIterator MyList::getEnd()
{
	MyIterator temp;
	temp.it = end;
	return temp;
}

void MyList::push_back_current_level(std::string data)
{
	if (begin->data == "")
	{
		end->data = data;
		return;
	}
	end->next = new Node;
	end->next->data = data;
	end = end->next;
}

void MyList::push_back_next_level(std::string data)
{
	if (begin->data == "")
	{
		end->data = data;
		return;
	}
	end->down = new Node();
	end->down->data = data;
	end->down->level++;
}

std::pair<int, std::string> MyList::pop()
{
	return std::pair<int, std::string>();
}

void MyList::print()
{
}
