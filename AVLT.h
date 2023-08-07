
// AVLT - AVL Tree

#pragma once
#include<iostream>
#include<string>  
#include<queue>
#include<vector>
#include"SLLT.h"

using namespace std;

class AVLT
{
public:
    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        // string data;
        int balanceFactor = 0;
        //int index = -1;
        SLLT data;
    };

private:
    Node* root;

    Node* insert(Node*& p, bool& h, string data, int index);

    void cleanUpMemory(Node*& p);

    void deleteTree(Node*& p);

    short getKeyValue(std::string key);

    Node* minRight(Node* p, Node*& q, bool& h);

    bool compareKeys(Node* p, string data);

    Node* balancing(Node* p, bool& h, bool leftOrRight, bool isNodeDeleted);

    Node* find(Node* p, string data, int& compareCnt);

    Node* removeNode(Node* p, bool& h, string data, int index);

    string printNode(Node* currentNode, int h);

    std::vector<short> split(char spliter, std::string s);
    string nodeToString(Node* node, int h);

public:

    AVLT();

    void addNewNode(std::string key, int index);

    void deleteNode(std::string key, int index);

    void changeLastIndex(string key, int indexOfLast, int delIndex);

    Node* findNode(std::string key, int& compareCnt);

    void erase();

    string print(int h);

};

