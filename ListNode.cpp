#include "ListNode.h"
#include <iostream>
using namespace std;
Data::Data(int _index, int _series, int _number, std::string _Fio, int _percent, int _duration, int _sum) : index(_index), series(_series), number(_number), Fio(_Fio), percent(_percent), duration(_duration), sum(_sum) {}

bool  Data:: operator<=(const Data& other) {
    return Fio <= other.Fio;
}

bool  Data:: operator>=(const Data& other) {
    return Fio >= other.Fio;
}

bool Data:: operator==(const Data& other) const {
    return (number == other.number) && (series == other.series) && (Fio == other.Fio) && (percent == other.percent) && (sum == other.sum) && (duration == other.duration);
};

Data& Data::operator=(const Data& other) {
    if (this == &other) { return *this; }
    series = other.series;
    number = other.number;
    Fio = other.Fio;
    duration = other.duration;
    percent = other.percent;
    sum = other.sum;

    return *this;
}
void Data::setIndex(const int& _index) { index = _index; }
void Data::setSeries(const int& _series) { series = _series; }
void Data::setNumber(const int& _number) { number = _number; }
void Data::setFio(const std::string& _Fio) { Fio = _Fio; }
void Data::setPercent(const int& _percent) { percent = _percent; }
void Data::setDuration(const int& _duration) { duration = _duration; }
void Data::setSum(const int& _sum) { sum = _sum; }



ListNode::ListNode(Data& _date) : val(_date), count(1), next(nullptr) {}
int Data::getIndex() {
    return index;
}
int Data::getSeries() {
    return series;
}
int Data::getNumber() { return number; }
string  Data::getFio() { return Fio; }
int Data::getPercent() { return percent; }
int Data::getDuration() { return duration; }
int Data::getSum() { return sum; }





void ListNode::Push_front(ListNode*& head, Data date)
{
    ListNode* p = head;
    if (head != nullptr)
    {
        while (p->next != head && p->val.getFio() != date.getFio() && p->val.getPercent() != date.getPercent() &&
            p->val.getDuration() != date.getDuration() && p->val.getSum() != date.getSum() && p->val.getSeries() != date.getSeries() &&
            p->val.getNumber() != date.getNumber())
        {
            p = p->next;
        }
        if (p->val.getFio() == date.getFio() && p->val.getPercent() == date.getPercent() &&
            p->val.getDuration() == date.getDuration() && p->val.getSum() == date.getSum() && p->val.getSeries() != date.getSeries() &&
            p->val.getNumber() != date.getNumber())
        {
            p->count++;
        }
        else // ????? ???? ?????
        {

            ListNode* tmp = new ListNode(val);
            // inf field
            tmp->val = date;
            tmp->count = 1;
            tmp->next = head;
            p->next = tmp;
            head = tmp;
        }
    } // while

    else if (head == nullptr)
    {
        ListNode* tmp = new ListNode(val); // ?????? ???

        tmp->val = date;
        tmp->next = head;
        tmp->next = tmp;
        tmp->count++;
        head = tmp;
    }
};
void ListNode::remove_elem(ListNode* head, Data date)
{
    ListNode* p = head;
    if (p != nullptr)
    {
        if (p->val.getFio() == date.getFio() && p->val.getPercent() == date.getPercent() &&
            p->val.getDuration() == date.getDuration() && p->val.getSum() == date.getSum() && p->val.getSeries() == date.getSeries() &&
            p->val.getNumber() == date.getNumber() && p->count > 1)
        {
            p->count--;
        }
        else
        {
            while (p->next != head && p->next->val.getFio() == date.getFio() && p->next->val.getPercent() == date.getPercent() &&
                p->next->val.getDuration() == date.getDuration() && p->next->val.getSum() == date.getSum() && p->val.getSeries() == date.getSeries() &&
                p->val.getNumber() == date.getNumber())
            {
                p = p->next;
            }

            if (p->next != head)
            {
                if (p->next->val.getFio() == date.getFio() && p->next->val.getPercent() == date.getPercent() &&
                    p->next->val.getDuration() == date.getDuration() && p->next->val.getSum() == date.getSum() && p->val.getSeries() == date.getSeries() &&
                    p->val.getNumber() == date.getNumber() && p->count > 1)
                {
                    p->count--;
                }
                else
                {
                    ListNode* q = p->next;
                    p->next = q->next;
                    free(q);
                };
            }
        }
    }
}
void ListNode::PrintList(ListNode* head)
{
    ListNode* p = head;
    if (head == nullptr)
    {
        cout << "Cписок пуст" << endl;
        return;
    }
    else {




        while (p != head);
        {
            cout << p->val.getSeries() << " " << p->val.getNumber() << " " << p->val.getFio() << " "
                << p->val.getDuration() << " " << p->val.getPercent() << " " << p->val.getSum()
                << " (" << p->count << ")" << endl;
            p = p->next;
        }
    }

}
