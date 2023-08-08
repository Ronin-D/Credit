#include "HashTable.h"
#include <iostream>

HashTable::HashTable(int size)
{
    this->size = size;
    table = new pair<int, Data*>[size];
}

HashTable::~HashTable()
{
    for (size_t i = 0; i < size; i++)
    {
        if (table[i].first == 1)
        {
            delete table[i].second;
        }
    }
    delete[] table;
}

void HashTable::put(Data* data)
{
    int hash = hashFun(data);

    //bookedOffer->prehash = hash;

    if (table[hash].first == 0)
    {
        table[hash].second = data;
        table[hash].first = 1;
    }
    else {
        int j = 1;
        int k;
        if (size % 2 == 0)
        {
            k = 3;
        }
        else {
            k = 2;
        }
        if (compareCredits(table[hash].second, data))
        {
            cout << "key is not unique" << endl;
        }
        else {
            int i = resolveCollishion(hash, j, k);
            while (table[i].first != 0 && j <= size)
            {
                j++;
                i = resolveCollishion(hash, j, k);
            }
            if (table[i].first == 0)
            {
                table[i].second = data;
                table[i].first = 1;
            }
            else {
                std::cout << "out of memory" << endl;
            }
        }

    }
}
void HashTable::remove(Data* data)
{
    pair<int, int>findRes = findToRemove(data);
    int index = findRes.first;
    if (index != -1 && compareCredits(table[index].second, data))
    {
        int k;
        if (size % 2 == 0)
        {
            k = 3;
        }
        else
        {
            k = 2;
        }
        int save = index;
        vector<Data*>a;
        int hash = hashFun(table[index].second);
        int j = findRes.second + 1;
        index = resolveCollishion(hash, j, k);
        table[save].first = 0;
        delete table[save].second;
        Data* temp = nullptr;
        int i;
        while (table[index].first != 0
            && (hashFun(table[index].second) == hash ||
                hashFun(table[index].second) == save
                )
            )
        {
            temp = table[index].second;
            j++;
            i = index;
            index = resolveCollishion(hash, j, k);
        }
        if (temp != nullptr)
        {
            table[i].first = 0;
            table[i].second = nullptr;
            table[save].first = 1;
            table[save].second = temp;
        }
    }
}

int HashTable::find(Data* data)
{
    int hash = hashFun(data);
    if (table[hash].first == 0)
    {
        cout << "element is missing" << endl;
        return -1;
    }
    else if (compareCredits(table[hash].second,data))
    {
        return hash;
    }
    else {
        int j = 1;
        int k;
        if (size % 2 == 0)
        {
            k = 3;
        }
        else {
            k = 2;
        }
        int i = resolveCollishion(hash, j, k);
        while (table[i].first != 0
            && !compareCredits(table[i].second, data)
            && j <= size
            )
        {
            j++;
            i = resolveCollishion(hash, j, k);
        }
        if (table[i].first != 0 && compareCredits(table[i].second, data))
        {
            return i;
        }
        else {
            cout << "element is missing" << endl;
            return -1;
        }
    }

}

void HashTable::changeLastIndex(Data* lastElem, int delIndex)
{
    int elemIndex = find(lastElem);
    if (elemIndex != -1)
    {
        table[elemIndex].second->index = delIndex;
    }
}

int HashTable::hashFun(Data* data)
{
    int stringHash = 0;
    string bankName = data->bankName;

    for (size_t i = 0; i < bankName.length(); i++)
    {
        stringHash += bankName[i];
    }
    int passportHash = data->number + data->series;
    return (stringHash + passportHash) % size;
}


void HashTable::erase()
{
    for (int i = 0; i < size; i++)
    {
        if (table[i].first == 1)
        {
            delete table[i].second;
            table[i].first = 0;
        }
    }
}

bool HashTable::compareCredits(Data* data1, Data* data2)
{
    return /*(data1->bankName == data2->bankName &&
        data1->series == data2->series &&
        data1->interestRate == data2->interestRate&&
        data1->number == data2->number &&
        data1->sum == data2->sum&&
        data1->duration == data2->duration
        );*/
        (data1->bankName == data2->bankName &&
            data1->series == data2->series &&
            data1->number == data2->number);
}

pair<int, int> HashTable::findToRemove(Data* data)
{
    pair<int, int>res;
    int hash = hashFun(data);
    if (table[hash].first == 0)
    {
        cout << "element is missing" << endl;
        res.first = -1;
        res.second = -1;
        return res;
    }
    else if (compareCredits(table[hash].second, data))
    {
        res.first = hash;
        res.second = 0;
        return res;
    }
    else {
        int j = 1;
        int k;
        if (size % 2 == 0)
        {
            k = 3;
        }
        else {
            k = 2;
        }
        int i = resolveCollishion(hash, j, k);
        while (table[i].first != 0 && !compareCredits(table[i].second, data) && j <= size)
        {
            j++;
            i = resolveCollishion(hash, j, k);
        }
        if (table[i].first != 0 && compareCredits(table[i].second, data))
        {
            res.first = i;
            res.second = j;
            return res;
        }
        else {
            cout << "element is missing" << endl;
            res.first = -1;
            res.second = -1;
            return res;
        }
    }
}


int HashTable::resolveCollishion(int hash, int j, int k)
{
    return (hash + j * k) % size;
}