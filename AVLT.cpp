#include "AVlT.h"

AVLT::Node* AVLT::insert(Node*& p, bool& h, string data, int index)
{
	string pData;
	if (p != nullptr)
	{
		pData = p->data.head->data;
	}
	if (p == nullptr)
	{
		p = new Node();
		p->data.pushBack(data, index);
		h = true;
		return p;
	}
	else if (pData > data)
	{
		p->left = insert(p->left, h, data, index);
	}
	else if (pData < data)
	{
		p->right = insert(p->right, h, data, index);
	}
	else {
		p->data.pushBack(data, index);
	}
	return balancing(p, h, compareKeys(p, data), false);
}
AVLT::Node* AVLT::balancing(Node* p, bool& h, bool leftOrRight, bool isNodeDeleted) {

	if (leftOrRight) // если 1 значит рекурсия вернулась из левого поддерва 
	{
		if (h) //высота дерева изменилась 
		{
			if (isNodeDeleted == false)
			{
				if (p->balanceFactor == 1)
				{
					p->balanceFactor = 0;
					h = false;
				}
				else if (p->balanceFactor == 0) {
					p->balanceFactor = -1;
				}
				else if (p->balanceFactor == -1) { // require balancing

					Node* q = p->left;
					if (q->balanceFactor == -1) // right rotation
					{
						p->left = q->right;
						q->right = p;
						p->balanceFactor = 0;
						p = q;
					}
					else { // LR
						Node* temp = q->right;
						q->right = temp->left;
						temp->left = q;
						p->left = temp->right;
						temp->right = p;
						if (temp->balanceFactor == -1)
						{
							p->balanceFactor = 1;
						}
						else {
							p->balanceFactor = 0;
						}

						if (temp->balanceFactor == 1)
						{
							q->balanceFactor = -1;
						}
						else {
							q->balanceFactor = 0;
						}
						p = temp;
					}
					p->balanceFactor = 0;
					h = false;
				}
			}
			else { //balanceL
				Node* q = p->right;
				if (q->balanceFactor >= 0)
				{
					p->right = q->left;
					q->left = p;
					if (q->balanceFactor == 0)
					{
						p->balanceFactor = 1;
						q->balanceFactor = -1;
						h = false;
					}
					else {
						p->balanceFactor = 0;
						q->balanceFactor = 0;
					}
					p = q;
				}
				else {
					Node* temp = q->left;
					q->left = temp->right;
					temp->right = q;
					p->right = temp->left;
					temp->left = p;
					if (temp->balanceFactor == -1)
					{
						q->balanceFactor = 1;
					}
					else {
						q->balanceFactor = 0;
					}

					if (temp->balanceFactor == 1)
					{
						p->balanceFactor = -1;
					}
					else {
						p->balanceFactor = 0;
					}
					p = temp;
					temp->balanceFactor = 0;

				}
			}
		}
	}
	else
	{
		if (h)
		{
			if (isNodeDeleted == false)
			{
				if (p->balanceFactor == -1)
				{
					p->balanceFactor = 0;
					h = false;
				}
				else if (p->balanceFactor == 0) {
					p->balanceFactor = 1;
				}
				else if (p->balanceFactor == 1) { // left rotation

					Node* q = p->right;
					if (q->balanceFactor == 1)
					{
						p->right = q->left;
						q->left = p;
						p->balanceFactor = 0;
						p = q;
					}
					else { //RL
						Node* temp = q->left;
						q->left = temp->right;
						temp->right = q;
						p->right = temp->left;
						temp->left = p;
						if (temp->balanceFactor == -1)
						{
							q->balanceFactor = 1;
						}
						else {
							q->balanceFactor = 0;
						}
						if (temp->balanceFactor == 1)
						{
							p->balanceFactor = -1;
						}
						else {
							p->balanceFactor = 0;
						}
						p = temp;
					}
					p->balanceFactor = 0;
					h = false;
				}
			}
			else { //balanceR
				Node* q = p->left;
				if (q->balanceFactor <= 0)
				{
					p->left = q->right;
					q->right = p;
					if (q->balanceFactor = 0)
					{
						p->balanceFactor = -1;
						q->balanceFactor = 1;
						h = false;
					}
					else {
						p->balanceFactor = 0;
						q->balanceFactor = 0;
					}
					p = q;
				}
				else {
					Node* temp = q->right;
					q->right = temp->left;
					temp->left = q;
					p->left = temp->right;
					temp->right = p;
					if (temp->balanceFactor == -1)
					{
						p->balanceFactor = 1;
					}
					else {
						p->balanceFactor = 0;
					}

					if (temp->balanceFactor == 1)
					{
						q->balanceFactor = -1;
					}
					else {
						q->balanceFactor = 0;
					}
					p = temp;
					temp->balanceFactor = 0;
				}
			}

		}
	}
	return p;

}
AVLT::Node* AVLT::find(Node* p, string data, int& compareCnt)
{
	Node* res = nullptr;
	compareCnt++;
	if (p == nullptr)
	{
		return nullptr;
	}
	else if (p->data.head->data == data)
	{
		return p;
	}
	else if (p != nullptr)
	{
		if (compareKeys(p, data))
		{
			res = find(p->left, data, compareCnt);
		}
		else {
			res = find(p->right, data, compareCnt);
		}
	}
	return res;
}
void AVLT::cleanUpMemory(Node*& p)
{
	delete p;
	p = nullptr;
}

void AVLT::changeLastIndex(string key, int indexOfLast, int delIndex)
{
	int kostil = 0;
	auto node = findNode(key, kostil);
	if (node != nullptr)
	{
		auto tmp = node->data.head;
		if (tmp->index == indexOfLast)
		{
			tmp->index = delIndex;
		}
		else {
			tmp = tmp->next;
			while (tmp != node->data.head)
			{
				if (tmp->index == indexOfLast)
				{
					tmp->index = delIndex;
					break;
				}
				else {
					tmp = tmp->next;
				}
			}
		}
	}
}

short AVLT::getKeyValue(std::string key)
{
	short val = 0;
	if (key[0] != '0')
	{
		val = (key[0] - '0') * 10;
	}

	val += key[1] - '0';
	return val;
}

void AVLT::deleteTree(Node*& p)
{
	if (p == nullptr)
	{
		return;
	}
	if (p->data.head != nullptr)
	{
		p->data.erase();
	}
	deleteTree(p->left);
	deleteTree(p->right);
	cleanUpMemory(p);
}

AVLT::Node* AVLT::minRight(Node* p, Node*& q, bool& h)
{
	if (p->left == nullptr)
	{
		Node* temp = p->right;
		p->right = q->right;
		p->left = q->left;
		p->balanceFactor = q->balanceFactor;
		q = p;
		if (temp != nullptr || q->right == p)
		{
			q->right = temp;
		}
		h = true;
		return temp;

	}
	else {
		p->left = minRight(p->left, q, h);
		if (h)
		{
			if (p->balanceFactor == -1)
			{
				p->balanceFactor = 0;
				return p;
			}
			else if (p->balanceFactor == 0)
			{
				p->balanceFactor = 1;
				h = false;
				return p;
			}
			else if (p->balanceFactor == 1) {
				return balancing(p, h, true, true);
			}
		}
		else {
			return p;
		}

	}


}
bool AVLT::compareKeys(Node* p, string data)
{
	auto temp = p->data.head;
	if (p->data.head->data > data)
	{
		return true;
	}
	else if (p->data.head->data < data)
	{
		return false;
	}
	else {
		return true;
	}
}

string AVLT::nodeToString(Node* node, int h)
{
	string trusi;
	if (node != nullptr)
	{
		trusi += nodeToString(node->right, h + 26);
		for (int i = 1; i <= h; i++)
		{
			trusi += " ";
		}

		trusi += "[";
		auto current = node->data.head;
		while (current->next != node->data.head)
		{
			trusi += to_string(current->index);
			trusi += ",";
			current = current->next;
		}
		trusi += to_string(current->index);
		trusi += "]";

		trusi += node->data.head->data;
		trusi += "\n\n";
		trusi += nodeToString(node->left, h + 26);
	}
	return trusi;
}

string AVLT::printNode(Node* currentNode, int h)
{
	string trusi;
	if (root == nullptr)
	{
		return "Tree is empty. \n";
	}
	else
	{
		trusi += nodeToString(root->right, h + 26);
		for (int i = 1; i <= h; i++)
		{
			cout << " ";
		}

		trusi += "[";
		auto current = root->data.head;
		while (current->next != root->data.head)
		{
			trusi += to_string(current->index);
			trusi += ",";
			current = current->next;
		}
		trusi += to_string(current->index);
		trusi += "]";

		trusi += root->data.head->data;
		trusi += "\n\n";
		trusi += nodeToString(root->left, h + 26);
	}

	return trusi;
}

AVLT::Node* AVLT::removeNode(Node* p, bool& h, string data, int index)
{
	if (p == nullptr)
	{
		std::cout << "element is missing" << '\n';
		return nullptr;
	}
	auto list = p->data.head;
	if (list->data != data && list->index != index)
	{
		list = list->next;
		while (list != p->data.head)
		{
			if (list->data == data && list->index == index)
				break;
			else
				list = list->next;
		}
	}
	if (list->data == data && list->index == index)
	{
		p->data.deleteElement(data, index);
		//decriment
		if (p->data.head != nullptr)
		{
			return p;
		}
		else {
			Node* temp = p;
			if (temp->right == nullptr)
			{
				temp = p->left;
				cleanUpMemory(p);
				h = true;
				return temp;
			}
			else if (temp->left == nullptr)
			{
				temp = p->right;
				cleanUpMemory(p);
				h = true;
				return temp;
			}
			else {
				/*p->right = */minRight(p->right, p, h);
				if (h)
				{
					if (p->balanceFactor == 1)
					{
						p->balanceFactor = 0;
						return p;
					}
					else if (p->balanceFactor == 0)
					{
						p->balanceFactor = -1;
						h = false;
						return p;
					}
					else if (p->balanceFactor == -1) {
						return balancing(p, h, false, true);
					}

				}
				else {
					return p;
				}
			}
		}
	}
	else if (compareKeys(p, data))
	{

		p->left = removeNode(p->left, h, data, index);
		if (h) //уменьшено левое поддерево
		{
			if (p->balanceFactor == -1)
			{
				p->balanceFactor = 0;
				return p;
			}
			else if (p->balanceFactor == 0)
			{
				p->balanceFactor = 1;
				h = false;
				return p;
			}
			else if (p->balanceFactor == 1) {
				return balancing(p, h, true, true);
			}
		}
		else {
			return p;
		}
	}
	else if (!compareKeys(p, data)) {
		p->right = removeNode(p->right, h, data, index);
		if (h) // уменьшено правое
		{
			if (p->balanceFactor == 1)
			{
				p->balanceFactor = 0;
				return p;
			}
			else if (p->balanceFactor == 0)
			{
				p->balanceFactor = -1;
				h = false;
				return p;
			}
			else if (p->balanceFactor == -1) {
				return balancing(p, h, false, true);
			}
		}
		else {
			return p;
		}
	}

}

void AVLT::deleteNode(string key, int index)
{
	bool h = false;
	root = removeNode(root, h, key, index);

}

AVLT::Node* AVLT::findNode(std::string key, int& compareCnt)
{
	return find(root, key, compareCnt);
}

void AVLT::erase() {
	deleteTree(root);
}

AVLT::AVLT()
{
	root = nullptr;
}

void AVLT::addNewNode(std::string key, int index)
{
	Node* newElement = new Node();
	newElement->data.pushBack(key, index);
	if (root == nullptr)
	{
		root = newElement;
		root->balanceFactor = 0;
	}
	else {
		bool temp = false;
		root = insert(root, temp, newElement->data.head->data, newElement->data.head->index);
	}
}

string AVLT::print(int h)
{
	Node* temp = root;
	if (temp == nullptr)
	{
		std::cout << "nodes are missing" << '\n';
	}
	return printNode(temp, h);
}

