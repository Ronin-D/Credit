#include "SLLT.h"

SLLT::SLLT()
{
	head = nullptr;
}

void SLLT::cleanUpMemory(Node*& p)
{
	delete p;
	p = nullptr;
}

void SLLT::pushBack(string data, int index)
{
	Node* newElement = new Node();
	newElement->data = data;
	newElement->index = index;

	if (head == nullptr)
	{
		head = newElement;
		head->next = newElement;
	}
	else
	{
		Node* temp = head;
		while (temp->next != head && head->next != head)
		{
			temp = temp->next;
		}

		newElement->next = head;
		temp->next = newElement;

	}
}

void SLLT::pushSorted(string data, int index)
{
	Node* newElement = new Node();
	newElement->data = data;
	newElement->index = index;

	if (head == nullptr)
	{
		head = newElement;
		head->next = head;
	}
	else
	{
		Node* temp = head;
		while ((temp->next != head && head->next != head) && (newElement->index >= temp->next->index))
		{
			temp = temp->next;
		}

		if (temp == head && temp->index > newElement->index)
		{
			newElement->next = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}
			temp->next = newElement;
			head = newElement;
		}
		else
		{
			newElement->next = head;
			temp->next = newElement;
		}
	}
}

void SLLT::deleteElement(string data, int index)
{
	bool isElementDeleted = false;
	if (head != nullptr)
	{
		Node* temp = head;
		if (temp->data == data && temp->index == index && head->next != head)
		{
			while (temp->next != head)
			{
				temp = temp->next;
			}
			temp->next = head->next;
			temp = head;
			head = head->next;
			cleanUpMemory(temp);
			isElementDeleted = true;
		}
		else if (temp->data == data && temp->index == index && head->next == head)
		{
			cleanUpMemory(head);
			temp = nullptr;
			isElementDeleted = true;
		}
		while (!isElementDeleted && temp->next != head)
		{
			if (temp->next->data == data && temp->next->index == index)
			{
				if (temp->next->next == temp)
				{
					Node* target = temp->next;
					cleanUpMemory(target);
					temp->next = temp;
					isElementDeleted = true;
				}
				else
				{
					Node* target = temp->next;
					temp->next = temp->next->next;
					cleanUpMemory(target);
					isElementDeleted = true;
				}
			}
			temp = temp->next;
		}
		if (!isElementDeleted)
		{
			std::cout << "element is missing" << '\n';
		}
	}
	else
	{
		std::cout << "list is empty" << '\n';
	}
}

void SLLT::erase()
{
	if (head->next != nullptr)
	{
		Node* temp = head->next;
		while (temp != head)
		{
			Node* cur = temp;
			temp = temp->next;
			cleanUpMemory(cur);
		}
		cleanUpMemory(head);
	}
}
