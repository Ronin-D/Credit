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
	/*vector<Data> FindByVacancy(string vacancy, int& compareCnt);
	vector<Data> FindBySpeciality(string speciality, int& compareCnt);
	vector<Data> FindByCompany(string company, int& compareCnt);*/
private:
	string durationToString(int duration);
	string interestRateToString(int interestRate);
	string sumToString(int sum);
	//vector<Data> listToVector(ListNode list);
};

