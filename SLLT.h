#pragma once
#include<iostream>

using namespace std;

class SLLT
{

public:
	struct Node
	{
		string data;
		int index = -1;
		Node* next;
	};

private:

	void cleanUpMemory(Node*& p);

public:
	Node* head;

	SLLT();

	void pushBack(string data, int index);

	void pushSorted(string data, int index);

	void deleteElement(string data, int index);

	void erase();
};
