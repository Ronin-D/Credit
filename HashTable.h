#pragma once
#include<vector>
#include<string>
using namespace std;



class HashTable
{

public:

	struct Data
	{
		int index;
		int series;
		int number;
		std::string bankName;
		int interestRate;
		int duration;
		int sum;
	};

	HashTable(int size);
	~HashTable();
	void put(Data* data);
	//string print();
	void remove(Data* data);
	int find(Data* bookedOffer);
	void changeLastIndex(Data* lastElem, int delIndex);
	pair<int, Data*>* table;
	void erase();
	int size = -1;
	int hashFun(Data* data);
	int resolveCollishion(int hash, int j, int k);
private:
	bool compareCredits(Data* data1, Data* data2);
	pair <int, int>findToRemove(Data* data);
};

