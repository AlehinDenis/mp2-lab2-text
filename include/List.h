#include <string>
#pragma once
struct Node
{
	std::string data;
	Node* next = 0;
	Node* down = 0;
	int level;

public:
	/*Node()
	{

	}*/
};

class List
{
	Node* first = 0;
	Node* end = 0;

public:
	List()
	{
		first = new Node();
		first->next = end;
		end = first;
	}
	void push_back_current_level(std::string _data);
	void push_back_next_level(std::string _data);
	void pop();
	void print();
	~List();
};

void List::push_back_current_level(std::string _data)
{
	/*if (first == end)
	{
		end->data = _data;
		return;
	}*/
	Node* temp = new Node();
	temp->data = _data;
	end->next = temp;
	end = end->next;
}
void List::push_back_next_level(std::string _data)
{

}
void List::pop()
{

}
void List::print()
{

}
List::~List()
{

}
