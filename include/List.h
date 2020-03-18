#include <string>
#pragma once

struct Node
{
	std::string data;
	Node* next = 0;
	Node* down = 0;
	int level;

	Node(std::string Data = "", int Level = 1)
	{
		data = Data;
		level = Level;
		next = nullptr;
		down = nullptr;
	}

	void print()
	{
		std::cout << level << ". " << data << "\n";
		if (down != 0)
		{
			Node* tempDown = down;
			tempDown->print();
		}
		if (next != 0)
		{
			Node* tempNext = next;
			tempNext->print();
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Node node)
	{
		out << node.level << ". " << node.data << "\n";
		return out;
	}
};

struct MyIterator
{
	Node* it;

	std::pair<int, std::string>& operator*();
	std::pair<int, std::string>& operator->();

	MyIterator next();//"идет вправо"
	MyIterator endNext();//"идет вправо до упора"
	MyIterator nextLevel();//"идет вниз"
	MyIterator endNextLevel();//"идет вниз до упора"

	void insNext(std::string data); //"добавляет новый Node в next"
	void insDown(std::string data); //"добавляет новый Node в down"

	bool operator==(const MyIterator& iterator);
	bool operator!=(const MyIterator& iterator);
};

class MyList
{
	Node* begin = nullptr;
	Node* end = nullptr;
public:

	MyIterator getBegin();
	MyIterator getEnd();
	void push_back_current_level(std::string data); //"новый Node в end->next"
	void push_back_next_level(std::string data); //"новый Node в end->down"
	std::pair<int, std::string> pop();
	void print();
	//~MyList();
};