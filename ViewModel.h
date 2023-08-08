#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"AVLT.h"
#include"HashTable.h"

using namespace std;

class ViewModel
{
public:
	string path;
	vector<HashTable::Data*>data;
	AVLT bankNameTree;
	AVLT interestRateTree;
	AVLT maturityTimeTree;
	AVLT sumTree;
	HashTable* hashTable = nullptr;
	//HashTable* hashTable = nullptr;
	void readData(string dir, int hashTableSize);
	vector<HashTable::Data*> FindByBankName(string vacancy, int& compareCnt);
	vector<HashTable::Data*> FindByInterestRate(int interestRate, int& compareCnt);
	vector<HashTable::Data*> FindByMaturityTime(int maturityTime, int& compareCnt);
	vector<HashTable::Data*> FindBySum(int sum, int& compareCnt);
	string durationToString(int duration);
	string interestRateToString(int interestRate);
	string sumToString(int sum);
private:
	vector<HashTable::Data*> listToVector(SLLT list);
};

