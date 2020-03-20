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
	if(it != nullptr)	
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
	if (it != nullptr)
		while (it->down != nullptr)
			nextLevel();
	return *this;
}

void MyIterator::insNext(std::string data)
{
	if (it == nullptr)
		it = new Node(data);
	else
	{
		int lev = it->level;
		it->next = new Node(data, lev);
	}
}

void MyIterator::insDown(std::string data)
{
	if (it == nullptr)
		it = new Node(data);
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
	temp.it = begin;
	temp.endNext();
	return temp;
}

void MyList::push_back_current_level(std::string data)
{
	MyIterator temp;
	temp = getBegin();
	temp.endNext();
	temp.insNext(data);

	begin = temp.it;
	end = getEnd().it;
}

void MyList::push_back_next_level(std::string data)
{
	MyIterator temp;
	temp = getBegin();
	temp.endNextLevel();
	temp.insDown(data);

	begin = temp.it;
	end = getEnd().it;
}

std::pair<int, std::string> MyList::pop()
{
	std::pair<int, std::string> p(end->level, end->data);
	Node* temp = begin;
	while (temp->next != end)
	{
		temp = temp->next;
	}
	delete temp->next;
	temp->next = nullptr;
	end = temp;
	return p;
}

void MyList::print()
{
	begin->print();
}

MyList::~MyList()
{

}
