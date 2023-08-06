#include <iostream>
#include <time.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <vector>
#include <locale.h>
#include <algorithm>
#include <windows.h>
#include <set>
#include <string>
#include <cstdlib>
#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree() : root(nullptr) {};
AVLTree::TreeNode::TreeNode(ListNode* _data) : data(_data), left(nullptr), right(nullptr), bal(0) {};



void AVLTree::BalanceL(TreeNode*& root, bool& h)
{
    TreeNode* p1;
    TreeNode* p2;
    char bal1, bal2;
    switch (root->bal)
    {
    case -1:
        root->bal = 0;
        break;
    case 0:
        root->bal = 1;
        h = false;
        break;
    case 1:
        p1 = root->right;
        bal1 = p1->bal;
        if (bal1 >= 0)
        {
            root->right = p1->left;
            p1->left = root;
            if (bal1 == 0)
            {
                root->bal = 1;
                p1->bal = -1;
                h = false;
            }
            else
            {
                root->bal = 0;
                p1->bal = 0;
            }
            root = p1;
        }
        else
        {
            p2 = p1->left;
            bal2 = p2->bal;
            p1->left = p2->right;
            p2->right = p1;
            root->right = p2->left;
            p2->left = root;
            if (bal2 == 1)
                root->bal = -1;
            else
                root->bal = 0;
            if (bal2 == -1)
                p1->bal = 1;
            else
                p1->bal = 0;
            root = p2;
            p2->bal = 0;
        }
    }
}
void AVLTree::BalanceR(TreeNode*& root, bool& h)
{
    TreeNode* p1;
    TreeNode* p2;

    char bal1, bal2;
    switch (root->bal)
    {
    case 1:
        root->bal = 0;
        break;
    case 0:
        root->bal = 1;
        h = false;
        break;
    case -1:
        p1 = root->left;
        bal1 = p1->bal;
        if (bal1 <= 0)
        {
            root->left = p1->right;
            p1->right = root;
            if (bal1 == 0)
            {
                root->bal = -1;
                p1->bal = 1;
                h = false;
            }
            else
            {
                root->bal = 0;
                p1->bal = 0;
            }
            root = p1;
        }
        else
        {
            p2 = p1->right;
            bal2 = p2->bal;
            p1->right = p2->left;
            p2->left = p1;
            root->left = p2->right;
            p2->right = root;
            if (bal2 == -1)
                root->bal = 1;
            else
                root->bal = 0;
            if (bal2 == 1)
                p1->bal = -1;
            else
                p1->bal = 0;
            root = p2;
            p2->bal = 0;
        }
    }
}
// СЃСЂР°РІРЅРµРЅРёРµ РґР°РЅРЅС‹С… С‚РёРїР° Data
int Data::CompareFio(Data x, Data y)
{
    int len1 = x.getFio().length();
    int len2 = y.getFio().length();
    string s1 = x.getFio();
    string s2 = y.getFio();

    // Находим минимальную длину для итерации
    int min_len = min(len1, len2);

    // Итерируемся по символам строк и сравниваем их
    for (int i = 0; i < min_len; i++) {
        if (s1[i] < s2[i]) {
            return 1;
        }
        else if (s1[i] > s2[i]) {
            return -1;
        }
    }

    // Если все символы до минимальной длины строк совпадают,
    // проверяем, какая строка длиннее
    if (len1 < len2) {
        return 1;
    }
    else if (len1 > len2) {
        return -1;
    }
    else {
        return 0;
    }
};
int Data::ComparePer(Data x, Data y)
{
    if (x.getPercent() > y.getPercent()) {
        return -1;
    }
    else if (x.getPercent() < y.getPercent()) {
        return 1;
    }
    else {
        return 0;
    }
};

int Data::CompareDur(Data x, Data y)
{
    if (x.getDuration() > y.getDuration()) {
        return -1;
    }
    else if (x.getDuration() < y.getDuration()) {
        return 1;
    }
    else {
        return 0;
    }
}
int Data::CompareSum(Data x, Data y)
{
    if (x.getSum() > y.getSum()) {
        return -1;
    }
    else if (x.getSum() < y.getSum()) {
        return 1;
    }
    else {
        return 0;
    }
}
//ну теперь тип просто дальше изменять все мтода + дублирующие для каждого ключа    

//! INSERT INSERT INSERT INSERT INSERT INSERT

//  insert FIO
void AVLTree::insertByFio(Data infdata, TreeNode*& root, bool& h)
{
    TreeNode* p1;
    TreeNode* p2;


    if (root == nullptr)
    {
        root = new TreeNode(new ListNode(infdata));

        ListNode* head = new ListNode(infdata);
        head = nullptr;
        root->data = head;
        head->Push_front(root->data, infdata);
        h = true;
        root->bal = 0;
        root->left = root->right = nullptr;
    }
    else if (infdata.CompareFio(root->data->getData(), infdata) == 0) // Data x & Data y
    {

        root->data->getCount()++;
    }
    else if (infdata.CompareFio(root->data->getData(), infdata) == -1)
    {
        insertByFio(infdata, root->left, h);
        if (h && infdata.CompareFio(root->data->getData(), infdata) != 0)
        {

            if (root->bal == 1)
            {
                root->bal = 0;
                h = false;
            }
            else if (root->bal == 0)
            {
                root->bal = -1;
            }
            else
            {
                // ???? ???? ???
                p1 = root->left;
                if (p1->bal == -1)
                {
                    root->left = p1->right; // 1 ??? ???????
                    p1->right = root;
                    root->bal = 0;
                    root = p1;
                }
                else
                {
                    p2 = p1->right;
                    p1->right = p2->left;
                    p2->left = p1; // ??????? ?????
                    root->left = p2->right;
                    p2->right = root;
                    if (p2->bal == -1)
                    {
                        root->bal = 1;
                    }
                    else
                    {
                        root->bal = 0;
                    }
                    if (p2->bal == 1)
                    {
                        p1->bal = -1;
                    }
                    else
                    {
                        p1->bal = 0;
                    }
                    root = p2;
                }
                root->bal = 0;
                h = false;
            }
        }
    }

    else if (infdata.CompareFio(root->data->getData(), infdata) == 1) // ??????? ??????
    {
        insertByFio(infdata, root->right, h);
        if (h && infdata.CompareFio(root->data->getData(), infdata) != 0)
        {
            // ??????? ?????? ????
            if (root->bal == -1)
            {
                root->bal = 0;
                h = false;
            }
            else if (root->bal == 0)
            {
                root->bal = 1;
            }
            else
            { // bal=+1-- blalance
                p1 = root->right;
                if (p1->bal == 1)
                {
                    root->right = p1->left; // ??????? ?????? ???????
                    p1->left = root;
                    root->bal = 0;
                    root = p1;
                }
                else
                {
                    p2 = p1->left;
                    p1->left = p2->right;
                    p2->right = p1;
                    root->right = p2->left;
                    p2->left = root;

                    if (p2->bal == 1)
                    {
                        root->bal = -1;
                    }
                    else
                    {
                        root->bal = 0;
                    }
                    if (p2->bal == -1)
                    {
                        p1->bal = 1;
                    }
                    else
                    {
                        p1->bal = 0;
                    }
                    root = p2;
                }

                root->bal = 0;
                h = false;
            }
        }
    }
}

// insert Procent
void AVLTree::insertByPercent(Data infdata, TreeNode*& root, bool& h)
{
    TreeNode* p1;
    TreeNode* p2;
    bool isRus = false;
    for (char c : infdata.getFio()) {
        if (c <= 'a' && c >= 'я' || c <= 'А' && c >= 'Я') { isRus = true; }
    }
    if ((isRus == false) &&
        (infdata.getPercent() <= 1 && infdata.getPercent() >= 30) &&
        (infdata.getDuration() <= 1 && infdata.getDuration() >= 40) &&
        (infdata.getSum() <= 10000 && infdata.getSum() >= 99999)) {
        //mes-erroror
    }
    else {
        if (root == nullptr)
        {
            root = new TreeNode(new ListNode(infdata));

            ListNode* head = new ListNode(infdata);
            head = nullptr;
            root->data = head;
            head->Push_front(root->data, infdata);
            h = true;
            root->bal = 0;
            root->left = root->right = nullptr;
        }
        else if (infdata.ComparePer(root->data->getData(), infdata) == 0) // Data x & Data y
        {

            root->data->getCount()++;
        }
        else if (infdata.ComparePer(root->data->getData(), infdata) == -1)
        {
            insertByPercent(infdata, root->left, h);
            if (h && infdata.ComparePer(root->data->getData(), infdata) != 0)
            {

                if (root->bal == 1)
                {
                    root->bal = 0;
                    h = false;
                }
                else if (root->bal == 0)
                {
                    root->bal = -1;
                }
                else
                {
                    // ???? ???? ???
                    p1 = root->left;
                    if (p1->bal == -1)
                    {
                        root->left = p1->right; // 1 ??? ???????
                        p1->right = root;
                        root->bal = 0;
                        root = p1;
                    }
                    else
                    {
                        p2 = p1->right;
                        p1->right = p2->left;
                        p2->left = p1; // ??????? ?????
                        root->left = p2->right;
                        p2->right = root;
                        if (p2->bal == -1)
                        {
                            root->bal = 1;
                        }
                        else
                        {
                            root->bal = 0;
                        }
                        if (p2->bal == 1)
                        {
                            p1->bal = -1;
                        }
                        else
                        {
                            p1->bal = 0;
                        }
                        root = p2;
                    }
                    root->bal = 0;
                    h = false;
                }
            }
        }

        else if (infdata.ComparePer(root->data->getData(), infdata) == 1) // ??????? ??????
        {
            insertByPercent(infdata, root->right, h);
            if (h && infdata.ComparePer(root->data->getData(), infdata) != 0)
            {
                // ??????? ?????? ????
                if (root->bal == -1)
                {
                    root->bal = 0;
                    h = false;
                }
                else if (root->bal == 0)
                {
                    root->bal = 1;
                }
                else
                { // bal=+1-- blalance
                    p1 = root->right;
                    if (p1->bal == 1)
                    {
                        root->right = p1->left; // ??????? ?????? ???????
                        p1->left = root;
                        root->bal = 0;
                        root = p1;
                    }
                    else
                    {
                        p2 = p1->left;
                        p1->left = p2->right;
                        p2->right = p1;
                        root->right = p2->left;
                        p2->left = root;

                        if (p2->bal == 1)
                        {
                            root->bal = -1;
                        }
                        else
                        {
                            root->bal = 0;
                        }
                        if (p2->bal == -1)
                        {
                            p1->bal = 1;
                        }
                        else
                        {
                            p1->bal = 0;
                        }
                        root = p2;
                    }

                    root->bal = 0;
                    h = false;
                }
            }
        }
    }//end else
}

//insert Duration
void AVLTree::insertByDuration(Data infdata, TreeNode*& root, bool& h)
{
    TreeNode* p1;
    TreeNode* p2;
    bool isRus = false;
    for (char c : infdata.getFio()) {
        if (c <= 'a' && c >= 'я' || c <= 'А' && c >= 'Я') { isRus = true; }
    }
    if ((isRus == false) ||
        (infdata.getPercent() <= 1 && infdata.getPercent() >= 30) ||
        (infdata.getDuration() <= 1 && infdata.getDuration() >= 40) ||
        (infdata.getSum() <= 10000 && infdata.getSum() >= 99999)) {
        //mes-erroror
    }
    else {

        if (root == nullptr)
        {
            root = new TreeNode(new ListNode(infdata));

            ListNode* head = new ListNode(infdata);
            head = nullptr;
            root->data = head;
            head->Push_front(root->data, infdata);
            h = true;
            root->bal = 0;
            root->left = root->right = nullptr;
        }
        else if (infdata.CompareDur(root->data->getData(), infdata) == 0) // Data x & Data y
        {

            root->data->getCount()++;
        }
        else if (infdata.CompareDur(root->data->getData(), infdata) == -1)
        {
            insertByDuration(infdata, root->left, h);
            if (h && infdata.CompareDur(root->data->getData(), infdata) != 0)
            {

                if (root->bal == 1)
                {
                    root->bal = 0;
                    h = false;
                }
                else if (root->bal == 0)
                {
                    root->bal = -1;
                }
                else
                {
                    // ???? ???? ???
                    p1 = root->left;
                    if (p1->bal == -1)
                    {
                        root->left = p1->right; // 1 ??? ???????
                        p1->right = root;
                        root->bal = 0;
                        root = p1;
                    }
                    else
                    {
                        p2 = p1->right;
                        p1->right = p2->left;
                        p2->left = p1; // ??????? ?????
                        root->left = p2->right;
                        p2->right = root;
                        if (p2->bal == -1)
                        {
                            root->bal = 1;
                        }
                        else
                        {
                            root->bal = 0;
                        }
                        if (p2->bal == 1)
                        {
                            p1->bal = -1;
                        }
                        else
                        {
                            p1->bal = 0;
                        }
                        root = p2;
                    }
                    root->bal = 0;
                    h = false;
                }
            }
        }

        else if (infdata.CompareDur(root->data->getData(), infdata) == 1) // ??????? ??????
        {
            insertByDuration(infdata, root->right, h);
            if (h && infdata.CompareDur(root->data->getData(), infdata) != 0)
            {
                // ??????? ?????? ????
                if (root->bal == -1)
                {
                    root->bal = 0;
                    h = false;
                }
                else if (root->bal == 0)
                {
                    root->bal = 1;
                }
                else
                { // bal=+1-- blalance
                    p1 = root->right;
                    if (p1->bal == 1)
                    {
                        root->right = p1->left; // ??????? ?????? ???????
                        p1->left = root;
                        root->bal = 0;
                        root = p1;
                    }
                    else
                    {
                        p2 = p1->left;
                        p1->left = p2->right;
                        p2->right = p1;
                        root->right = p2->left;
                        p2->left = root;

                        if (p2->bal == 1)
                        {
                            root->bal = -1;
                        }
                        else
                        {
                            root->bal = 0;
                        }
                        if (p2->bal == -1)
                        {
                            p1->bal = 1;
                        }
                        else
                        {
                            p1->bal = 0;
                        }
                        root = p2;
                    }

                    root->bal = 0;
                    h = false;
                }
            }
        }
    }
}
//insert SUMMA
void AVLTree::insertBySum(Data infdata, TreeNode*& root, bool& h)
{
    TreeNode* p1;
    TreeNode* p2;
    bool isRus = false;
    for (char c : infdata.getFio()) {
        if (c <= 'a' && c >= 'я' || c <= 'А' && c >= 'Я') { isRus = true; }
    }


    if ((isRus == false) ||
        (infdata.getPercent() <= 1 && infdata.getPercent() >= 30) ||
        (infdata.getDuration() <= 1 && infdata.getDuration() >= 40) ||
        (infdata.getSum() <= 10000 && infdata.getSum() >= 99999)) {
        //mes-erroror
    }
    else {

        if (root == nullptr)
        {
            root = new TreeNode(new ListNode(infdata));

            ListNode* head = new ListNode(infdata);
            head = nullptr;
            root->data = head;
            head->Push_front(root->data, infdata);
            h = true;
            root->bal = 0;
            root->left = root->right = nullptr;
        }
        else if (infdata.CompareSum(root->data->getData(), infdata) == 0) // Data x & Data y
        {

            root->data->getCount()++;
        }
        else if (infdata.CompareSum(root->data->getData(), infdata) == -1)
        {
            insertBySum(infdata, root->left, h);
            if (h && infdata.CompareSum(root->data->getData(), infdata) != 0)
            {

                if (root->bal == 1)
                {
                    root->bal = 0;
                    h = false;
                }
                else if (root->bal == 0)
                {
                    root->bal = -1;
                }
                else
                {
                    // ???? ???? ???
                    p1 = root->left;
                    if (p1->bal == -1)
                    {
                        root->left = p1->right; // 1 ??? ???????
                        p1->right = root;
                        root->bal = 0;
                        root = p1;
                    }
                    else
                    {
                        p2 = p1->right;
                        p1->right = p2->left;
                        p2->left = p1; // ??????? ?????
                        root->left = p2->right;
                        p2->right = root;
                        if (p2->bal == -1)
                        {
                            root->bal = 1;
                        }
                        else
                        {
                            root->bal = 0;
                        }
                        if (p2->bal == 1)
                        {
                            p1->bal = -1;
                        }
                        else
                        {
                            p1->bal = 0;
                        }
                        root = p2;
                    }
                    root->bal = 0;
                    h = false;
                }
            }
        }

        else if (infdata.CompareSum(root->data->getData(), infdata) == 1) // ??????? ??????
        {
            insertBySum(infdata, root->right, h);
            if (h && infdata.CompareSum(root->data->getData(), infdata) != 0)
            {
                // ??????? ?????? ????
                if (root->bal == -1)
                {
                    root->bal = 0;
                    h = false;
                }
                else if (root->bal == 0)
                {
                    root->bal = 1;
                }
                else
                { // bal=+1-- blalance
                    p1 = root->right;
                    if (p1->bal == 1)
                    {
                        root->right = p1->left; // ??????? ?????? ???????
                        p1->left = root;
                        root->bal = 0;
                        root = p1;
                    }
                    else
                    {
                        p2 = p1->left;
                        p1->left = p2->right;
                        p2->right = p1;
                        root->right = p2->left;
                        p2->left = root;

                        if (p2->bal == 1)
                        {
                            root->bal = -1;
                        }
                        else
                        {
                            root->bal = 0;
                        }
                        if (p2->bal == -1)
                        {
                            p1->bal = 1;
                        }
                        else
                        {
                            p1->bal = 0;
                        }
                        root = p2;
                    }

                    root->bal = 0;
                    h = false;
                }
            }
        }
    }//end else
}

//!FIND    FIND    FIND  FIND FIND FIND FIND FIND 

int AVLTree::FindCountElem(TreeNode*& root, Data infdata)
{
    if (root->data->getData().CompareFio(root->data->getData(), infdata) == -1 || root->data->getData().CompareFio(root->data->getData(), infdata) == 1)
    {
        if (root->data->getData().CompareFio(root->data->getData(), infdata) == -1 && root->left != nullptr)
        { // x < that root => left
            FindCountElem(root->left, infdata);
        }
        else if (root->data->getData().CompareFio(root->data->getData(), infdata) == 1 && root->right != nullptr)
        {
            FindCountElem(root->right, infdata);
        }
    }
    else
    {
        // WriteValue(root);

        return root->data->getCount();
    }
}


// find Fio
AVLTree::TreeNode* AVLTree::FindElemByFio(TreeNode*& root, Data infdata)
{
    if (root == nullptr)
    {
        cout << "Element not found." << endl;
        return nullptr;
    }

    int comparison = root->data->getData().CompareFio(root->data->getData(), infdata);
    if (comparison == 0)
    {
        // cout << "Find is:" << endl;
        // root->data->PrintList(root->data);
        // cout << "Address: " << root << endl;
        return root;
    }
    else if (comparison == -1 && root->left != nullptr)
    {
        FindElemByFio(root->left, infdata);
    }
    else if (comparison == 1 && root->right != nullptr)
    {
        FindElemByFio(root->right, infdata);
    }
}

// find duration
void AVLTree::FindElemByDur(TreeNode*& root, Data infdata)
{
    if (root == nullptr)
    {
        cout << "Element not found." << endl;
        return;
    }

    int comparison = root->data->getData().CompareDur(root->data->getData(), infdata);
    if (comparison == 0)
    {
        cout << "Find is:" << endl;
        root->data->PrintList(root->data);
        cout << "Address: " << root << endl;
    }
    else if (comparison == -1 && root->left != nullptr)
    {
        FindElemByDur(root->left, infdata);
    }
    else if (comparison == 1 && root->right != nullptr)
    {
        FindElemByDur(root->right, infdata);
    }
}
// insert percent
void AVLTree::FindElemByPer(TreeNode*& root, Data infdata)
{
    if (root == nullptr)
    {
        cout << "Element not found." << endl;
        return;
    }

    int comparison = root->data->getData().ComparePer(root->data->getData(), infdata);
    if (comparison == 0)
    {
        cout << "Find is:" << endl;
        root->data->PrintList(root->data);
        cout << "Address: " << root << endl;
    }
    else if (comparison == -1 && root->left != nullptr)
    {
        FindElemByPer(root->left, infdata);
    }
    else if (comparison == 1 && root->right != nullptr)
    {
        FindElemByPer(root->right, infdata);
    }
}
// insert summa
void AVLTree::FindElemBySum(TreeNode*& root, Data infdata)
{
    if (root == nullptr)
    {
        cout << "Element not found." << endl;
        return;
    }

    int comparison = root->data->getData().CompareSum(root->data->getData(), infdata);
    if (comparison == 0)
    {
        cout << "Find is:" << endl;
        root->data->PrintList(root->data);
        cout << "Address: " << root << endl;
    }
    else if (comparison == -1 && root->left != nullptr)
    {
        FindElemBySum(root->left, infdata);
    }
    else if (comparison == 1 && root->right != nullptr)
    {
        FindElemBySum(root->right, infdata);
    }
}


//! DEL  DEL DEL DEL DEL DEL DEL DEL DEL DEL
void AVLTree::Del(TreeNode*& r, TreeNode*& q, bool& h)
{
    if (r->left)
    {
        Del(r->left, q, h);
        if (h)
            BalanceL(r, h);
    }
    else
    {
        q->data = r->data;
        // q->Key->val=r->Key->val
        q = r;
        r = r->right;
        h = true;
    }
}
// delete fio
void AVLTree::DeletebyFio(TreeNode*& root, bool& h, Data infdata)
{
    TreeNode* q;
    if (!root)
    {
    }
    else
    {
        if (FindCountElem(root, infdata) > 1)
        {
            if (root->data->getData().CompareFio(root->data->getData(), infdata) == -1)
            {
                DeletebyFio(root->left, h, infdata);
            }
            else if (root->data->getData().CompareFio(root->data->getData(), infdata) == 1)
            {
                DeletebyFio(root->right, h, infdata);
            }
            else
            {
                root->data->getCount()--;
            }

            exit;
        }
        else if (root->data->getData().CompareFio(root->data->getData(), infdata) == 1)
        {

            if (root->data->getData().CompareFio(root->data->getData(), infdata) == -1)
            {
                DeletebyFio(root->left, h, infdata);
                if (root->data->getCount() > 1)
                {
                    root->data->getCount()--;
                }
                if (h)
                    BalanceL(root, h);
            }
            else if (root->data->getData().CompareFio(root->data->getData(), infdata) == 1)
            {
                DeletebyFio(root->right, h, infdata);
                if (h)
                    BalanceR(root, h);
            }
            else
            {
                q = root;
                if (!q->right)
                {
                    root = q->left;
                    h = true;
                }
                else if (!q->left)
                {
                    root = q->right;
                    h = true;
                }
                else
                {
                    Del(q->right, q, h);
                    if (h)
                        BalanceR(root, h);
                }
            }
        }
    }
}
// delete dur
void AVLTree::DeletebyDur(TreeNode*& root, bool& h, Data infdata)
{
    TreeNode* q;
    if (!root)
    {
    }
    else
    {
        if (FindCountElem(root, infdata) > 1)
        {
            if (root->data->getData().CompareDur(root->data->getData(), infdata) == -1)
            {
                DeletebyDur(root->left, h, infdata);
            }
            else if (root->data->getData().CompareDur(root->data->getData(), infdata) == 1)
            {
                DeletebyDur(root->right, h, infdata);
            }
            else
            {
                root->data->getCount()--;
            }

            exit;
        }
        else if (root->data->getData().CompareDur(root->data->getData(), infdata) == 1)
        {

            if (root->data->getData().CompareDur(root->data->getData(), infdata) == -1)
            {
                DeletebyDur(root->left, h, infdata);
                if (root->data->getCount() > 1)
                {
                    root->data->getCount()--;
                }
                if (h)
                    BalanceL(root, h);
            }
            else if (root->data->getData().CompareDur(root->data->getData(), infdata) == 1)
            {
                DeletebyDur(root->right, h, infdata);
                if (h)
                    BalanceR(root, h);
            }
            else
            {
                q = root;
                if (!q->right)
                {
                    root = q->left;
                    h = true;
                }
                else if (!q->left)
                {
                    root = q->right;
                    h = true;
                }
                else
                {
                    Del(q->right, q, h);
                    if (h)
                        BalanceR(root, h);
                }
            }
        }
    }
}
// delete persent
void AVLTree::DeletebyPer(TreeNode*& root, bool& h, Data infdata)
{
    TreeNode* q;
    if (!root)
    {
    }
    else
    {
        if (FindCountElem(root, infdata) > 1)
        {
            if (root->data->getData().ComparePer(root->data->getData(), infdata) == -1)
            {
                DeletebyPer(root->left, h, infdata);
            }
            else if (root->data->getData().ComparePer(root->data->getData(), infdata) == 1)
            {
                DeletebyPer(root->right, h, infdata);
            }
            else
            {
                root->data->getCount()--;
            }

            exit;
        }
        else if (root->data->getData().ComparePer(root->data->getData(), infdata) == 1)
        {

            if (root->data->getData().ComparePer(root->data->getData(), infdata) == -1)
            {
                DeletebyDur(root->left, h, infdata);
                if (root->data->getCount() > 1)
                {
                    root->data->getCount()--;
                }
                if (h)
                    BalanceL(root, h);
            }
            else if (root->data->getData().ComparePer(root->data->getData(), infdata) == 1)
            {
                DeletebyPer(root->right, h, infdata);
                if (h)
                    BalanceR(root, h);
            }
            else
            {
                q = root;
                if (!q->right)
                {
                    root = q->left;
                    h = true;
                }
                else if (!q->left)
                {
                    root = q->right;
                    h = true;
                }
                else
                {
                    Del(q->right, q, h);
                    if (h)
                        BalanceR(root, h);
                }
            }
        }
    }
}
// delete sum
void AVLTree::DeletebySum(TreeNode*& root, bool& h, Data infdata)
{
    TreeNode* q;
    if (!root)
    {
    }
    else
    {
        if (FindCountElem(root, infdata) > 1)
        {
            if (root->data->getData().CompareSum(root->data->getData(), infdata) == -1)
            {
                DeletebySum(root->left, h, infdata);
            }
            else if (root->data->getData().CompareSum(root->data->getData(), infdata) == 1)
            {
                DeletebySum(root->right, h, infdata);
            }
            else
            {
                root->data->getCount()--;
            }

            exit;
        }
        else if (root->data->getData().CompareSum(root->data->getData(), infdata) == 1)
        {

            if (root->data->getData().CompareSum(root->data->getData(), infdata) == -1)
            {
                DeletebySum(root->left, h, infdata);
                if (root->data->getCount() > 1)
                {
                    root->data->getCount()--;
                }
                if (h)
                    BalanceL(root, h);
            }
            else if (root->data->getData().CompareSum(root->data->getData(), infdata) == 1)
            {
                DeletebySum(root->right, h, infdata);
                if (h)
                    BalanceR(root, h);
            }
            else
            {
                q = root;
                if (!q->right)
                {
                    root = q->left;
                    h = true;
                }
                else if (!q->left)
                {
                    root = q->right;
                    h = true;
                }
                else
                {
                    Del(q->right, q, h);
                    if (h)
                        BalanceR(root, h);
                }
            }
        }
    }
}



// РѕСЃРІРѕР±РѕР¶РґРµРЅРёРµ РїР°РјСЏС‚Рё
void AVLTree::deleteAll(TreeNode*& root)
{
    if (root->left)
        deleteAll(root->left);
    if (root->right)
        deleteAll(root->right);
    delete root;
    root = nullptr;
}


// РїРµС‡Р°С‚ РґРµСЂРµРІР°
void AVLTree::PrintTree(TreeNode*& root, int h)
{

    if (root != nullptr)
    {
        PrintTree(root->right, h + 12);
        for (int i = 1; i < h; i++)
        {
            cout << ' ';
        };
        root->data->PrintList(root->data);

        PrintTree(root->left, h + 12);
    }
}


int AVLTree::CountElem(TreeNode*& root)
{
    int i;
    if (root == nullptr)
        return (0);
    i = root->data->getCount() + CountElem(root->left) + CountElem(root->right);

    return i;
}


void AVLTree::changeLastIndex(TreeNode*& root, Data infdata, int indexOfLast, int delIndex) {
    auto node = FindElemByFio(root, infdata);
    if (node != nullptr)
    {
        auto tmp = node->data->next;
        if (tmp->val.getIndex() == indexOfLast) {
            tmp->val.setIndex(delIndex);
        }
        else {
            tmp = tmp->next;
            while (tmp != node->data->next) {
                if (tmp->val.getIndex() == indexOfLast)
                {
                    tmp->val.setIndex(delIndex); break;
                }
                else {
                    tmp = tmp->next;
                }


            }
        }
    }
}