#pragma once

#include "ListNode.h"

class AVLTree {
protected:
    struct TreeNode {
        ListNode* data;
        TreeNode* left;
        TreeNode* right;
        int bal;

        TreeNode(ListNode* data);
    };
    TreeNode* root;



public:


    AVLTree();
    ~AVLTree();
    void BalanceL(TreeNode*& root, bool& h);
    void BalanceR(TreeNode*& root, bool& h);
    //insert
    void insertByFio(Data infdata, TreeNode*& root, bool& h);
    void insertByPercent(Data infdata, TreeNode*& root, bool& h);
    void insertByDuration(Data infdata, TreeNode*& root, bool& h);
    void insertBySum(Data infdata, TreeNode*& root, bool& h);


    //find
    int FindCountElem(TreeNode*& root, Data infdata);
    AVLTree::TreeNode* AVLTree::FindElemByFio(TreeNode*& root, Data infdata);
    void FindElemByDur(TreeNode*& root, Data infdata);
    void FindElemByPer(TreeNode*& root, Data infdata);
    void FindElemBySum(TreeNode*& root, Data infdata);
    //delete
    void Del(TreeNode*& r, TreeNode*& q, bool& h);
    void DeletebyFio(TreeNode*& root, bool& h, Data infdata);
    void DeletebyPer(TreeNode*& root, bool& h, Data infdata);
    void DeletebyDur(TreeNode*& root, bool& h, Data infdata);
    void DeletebySum(TreeNode*& root, bool& h, Data infdata);
    void deleteAll(TreeNode*& root);


    void changeLastIndex(TreeNode*& root, Data infdata, int indexOfLast, int delIndex);

    void PrintTree(TreeNode*& root, int h);
    int CountElem(TreeNode*& root);



};
