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

	MyIterator next();//"���� ������"
	MyIterator endNext();//"���� ������ �� �����"
	MyIterator nextLevel();//"���� ����"
	MyIterator endNextLevel();//"���� ���� �� �����"

	void insNext(std::string data); //"��������� ����� Node � next"
	void insDown(std::string data); //"��������� ����� Node � down"

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
	void push_back_current_level(std::string data); //"����� Node � end->next"
	void push_back_next_level(std::string data); //"����� Node � end->down"
	std::pair<int, std::string> pop();
	void print();
	//~MyList();
};