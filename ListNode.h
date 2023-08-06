#pragma once
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Data {
protected:
    int index;
    int series;
    int number;
    std::string Fio;
    int percent;
    int duration;
    int sum;


public:

    Data() {};
    Data(int index, int series, int number, std::string Fio, int percent, int duration, int sum);

    bool operator==(const Data& other) const;
    Data& operator=(const Data& other);
    bool  operator<=(const Data& other);
    bool   operator>=(const Data& other);

    int getIndex();
    int getSeries();
    int getNumber();
    std::string getFio();
    int getPercent();
    int getDuration();
    int getSum();


    void setIndex(const int& _index);
    void setSeries(const int& _series);
    void setNumber(const int& _number);
    void setFio(const std::string& _Fio);
    void setPercent(const int& _percent);
    void setDuration(const int& _duration);
    void setSum(const int& _sum);





    int CompareFio(Data x, Data y);
    int ComparePer(Data x, Data y);
    int CompareDur(Data x, Data y);
    int CompareSum(Data x, Data y);
    void FromStringInt(string s, Data& infdata);


    friend class ListNode;

};

class ListNode {
public:
    Data val;
    int count;
    ListNode* next;
public:
    ListNode(Data& date);
    Data getData() {
        return val;
    }
    int& getCount() {
        return count;
    }

    void Push_front(ListNode*& head, Data date);
    void remove_elem(ListNode* head, Data date);
    void PrintList(ListNode* head);


};