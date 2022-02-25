/*********************
# Name: Caroline Kim
# Data Structure
# Coding Asg 07 - bintres.cpp
# Creating a binary tree object working with struct Data and struct Node.
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include <iostream>
#include "data.h"
#include "functions.h"

using std::cout;
using std::endl;

class BinTree{

public:
    BinTree();
    ~BinTree();

    bool isEmpty();
    bool getRootData(Data*);
    int getCount();
    void displayTree();

    void clear();
    bool addNode(int, const string*);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);

    int getHeight();

    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

private:

    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);

    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);

    int getHeight(DataNode*);

    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);

    //Added according to the written algo
    DataNode* minValueNode(DataNode*);

    DataNode *root;
    int count;

};

#endif /* BINTREE_BINTREE_H */

