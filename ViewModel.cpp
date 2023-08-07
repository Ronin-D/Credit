#include "ViewModel.h"


void ViewModel::readData(string dir, int hashTableSize)
{
	ifstream fin;
	fin.open(dir);
	string s;
	//hashTable = new HashTable(hashTableSize);
	while (getline(fin, s))
	{
		Data *credit = new Data();
		size_t pos = 0;
		vector<string>split;
		while ((pos = s.find('.')) != std::string::npos) {
			split.push_back(s.substr(0, pos));
			s.erase(0, pos + 1);
		}
		split.push_back(s);
		if (data.size() < hashTableSize)
		{
			credit->series = stoi(split[0]);
			credit->number = stoi(split[1]);
			credit->bankName = split[2];
			credit->interestRate = stoi(split[3]);
			credit->duration = stoi(split[4]);
			credit->sum = stoi(split[5]);
			data.push_back(credit);
			credit->index = data.size() - 1;

			bankNameTree.addNewNode(credit->bankName, credit->index);
			interestRateTree.addNewNode(interestRateToString(credit->interestRate), credit->index);
			maturityTimeTree.addNewNode(durationToString(credit->duration), credit->index);
			sumTree.addNewNode(sumToString(credit->sum), credit->index);

			//hashTable->Add2(credit);
		}
		else
		{
			fin.close();
			break;
		}
	}
	fin.close();
}

string ViewModel::durationToString(int duration)
{
	string dur = to_string(duration);
	if (dur.length()<2)
	{
		dur = "0" + dur;
	}
	return dur;
}

string ViewModel::interestRateToString(int interestRate)
{

	string rate= to_string(interestRate);
	if (rate.length() < 2)
	{
		rate = "0" + rate;
	}
	return rate;
}

string ViewModel::sumToString(int sum)
{
	return to_string(sum);
}
