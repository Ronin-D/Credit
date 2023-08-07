#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"AVLT.h"

using namespace std;

class ViewModel
{
public:
	struct Data
	{
		int index;
		int series;
		int number;
		string bankName;
		int interestRate;
		int duration;
		int sum;
	};
	string path;
	vector<Data*>data;
	AVLT bankNameTree;
	AVLT interestRateTree;
	AVLT maturityTimeTree;
	AVLT sumTree;

	//HashTable* hashTable = nullptr;
	void readData(string dir, int hashTableSize);
	vector<Data*> FindByBankName(string vacancy, int& compareCnt);
	vector<Data*> FindByInterestRate(int interestRate, int& compareCnt);
	vector<Data*> FindByMaturityTime(int maturityTime, int& compareCnt);
	vector<Data*> FindBySum(int sum, int& compareCnt);
private:
	string durationToString(int duration);
	string interestRateToString(int interestRate);
	string sumToString(int sum);
	vector<Data*> listToVector(SLLT list);
};

