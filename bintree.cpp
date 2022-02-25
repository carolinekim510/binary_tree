/*********************
# Name: Caroline Kim
# Data Structure
# Coding Asg 07 - bintree.cpp
# Creating a binary tree object working with struct Data and struct Node.
**********************/

#include "bintree.h"

BinTree::BinTree() {
    root = nullptr;
    count = 0;
}

BinTree::~BinTree() { clear(); }

/*********************
 *
 *  Public methods
 *
 *********************/

bool BinTree::isEmpty()
{
    bool empty = false;
    if (root != nullptr){
        empty = true;
    }
    return empty;
}


bool BinTree::getRootData(Data* temp)
{
    bool success = false;
    if(root != nullptr){
        temp->id = root->data.id;
        temp->information = root->data.information;
        success = true;
    } else {
        temp->id = -1;
        temp->information = "";
    }
    return success;
}


int BinTree::getCount(){ return count; }


void BinTree::displayTree(){
    if(!isEmpty()){
        displayPreOrder();
        displayInOrder();
        displayPostOrder();
    } else {
        cout << "Tree is empty" << endl;
    }
}


void BinTree::clear(){
    clear(root);
    count = 0;
}


bool BinTree::addNode(int id, const string* info){
    bool added = false;
    if(id > 0 && !info->empty()){
        DataNode *newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = *info;
        newNode->left = nullptr;
        newNode->right = nullptr;
        added = addNode(newNode, &root);
        count++;
    }
    return added;
}


bool BinTree::removeNode(int id){
    bool removed = false;
    if(id > 0){
        int tempCount = count;
        root = removeNode(id, root);
        if (count < tempCount) {
            removed = true;
        }
    }
    return removed;
}


bool BinTree::getNode(Data* dataRoot, int id){
    bool success = false;
    if(id > 0){
        success = getNode(dataRoot, id, root);
    }
    return success;
}

bool BinTree::contains(int id){
    bool success = false;
    if(id > 0){
        success = contains(id,  root);
    }
    return success;
}


int BinTree::getHeight()
{
    int height = getHeight(root);
    return height;
}

void BinTree::displayPreOrder(){ displayPreOrder(root); }
void BinTree::displayPostOrder(){ displayPostOrder(root); }
void BinTree::displayInOrder(){ displayInOrder(root); }




/*********************
 *
 *  Private methods
 *
 *********************/

void BinTree::clear(DataNode* dataRoot)
{
    if(dataRoot != nullptr){
        if(dataRoot->left){
            clear(dataRoot->left);
            dataRoot->left = nullptr;
        }
        if(dataRoot->right){
            clear(dataRoot->right);
            dataRoot->right = nullptr;
        }
        delete root;
        root = nullptr;
    }
}


bool BinTree::addNode(DataNode* dataRoot, DataNode** root)
{
    bool added = false;
    if(*root == nullptr){
        *root = dataRoot;
        added = true;
    } else if(dataRoot->data.id < (*root)->data.id){
        added = addNode(dataRoot, &(*root)->left);
    } else {
        added = addNode(dataRoot, &(*root)->right);
    }
    return added;
}

DataNode* BinTree::removeNode(int id, DataNode* dataRoot)
{
    if(dataRoot == nullptr){
        return dataRoot;
    } else {
        if(id < dataRoot->data.id){
            dataRoot->left = removeNode(id, dataRoot->left);
        } else if(id > dataRoot->data.id){
            dataRoot->right = removeNode(id, dataRoot->right);
        } else {
            DataNode *temp;
            if(dataRoot->left == NULL){
                temp = dataRoot->right;
                delete dataRoot;
                dataRoot = temp;
                count--;
            } else if(dataRoot->right == NULL){
                temp = dataRoot->left;
                delete dataRoot;
                dataRoot = temp;
                count--;
            } else {
                temp = minValueNode(dataRoot->right);
                dataRoot->data.id = temp->data.id;
                dataRoot->data.information = temp->data.information;
                dataRoot->right = removeNode(temp->data.id, dataRoot->right);
            }
        }
    }
    return dataRoot;
}


bool BinTree::getNode(Data* temp, int id, DataNode* dataRoot)
{
    bool success = false;
    if(dataRoot){
        if(id == dataRoot->data.id){
            temp->information = dataRoot->data.information;
            success = true;
        } else if (id < dataRoot->data.id){
            success = contains(id, dataRoot->left);
        } else {
            success = contains(id, dataRoot->right);
        }
    }
    return success;
}


bool BinTree::contains(int id, DataNode* dataRoot)
{
    bool success = false;
    if(dataRoot != nullptr){
        if(id == dataRoot->data.id){
            success = true;
        } else if(id < dataRoot->data.id){
            success = contains(id, dataRoot->left);
        } else {
            success = contains(id, dataRoot->right);
        }
    }
    return success;
}

int BinTree::getHeight(DataNode* dataRoot)
{
    int lh, rh = 0;
    if(dataRoot == nullptr){
        return 0;
    } else {
        lh = getHeight(dataRoot->left);
        rh = getHeight(dataRoot->right);
        if (lh > rh){
            return lh + 1;
        } else {
            return rh + 1;
        }
    }
}

void BinTree::displayPreOrder(DataNode* dataRoot)
{

    if(dataRoot){
        cout << dataRoot->data.id << " " << dataRoot->data.information << endl;
        if(dataRoot->left){
            displayInOrder(dataRoot->left);
        }
        if(dataRoot->right){
            displayInOrder(dataRoot->right);
        }
    }
}


void BinTree::displayPostOrder(DataNode* dataRoot)
{
    if(dataRoot){
        if(dataRoot->left){
            displayInOrder(dataRoot->left);
        }
        if(dataRoot->right){
            displayInOrder(dataRoot->right);
        }
        cout << dataRoot->data.id << " " << dataRoot->data.information << endl;
    }

}


void BinTree::displayInOrder(DataNode* dataRoot)
{
    if(dataRoot){
        if(dataRoot->left){
            displayInOrder(dataRoot->left);
        }
        cout << dataRoot->data.id << " " << dataRoot->data.information << endl;
        if(dataRoot->right){
            displayInOrder(dataRoot->right);
        }
    }
}

// Additional
DataNode* BinTree::minValueNode(DataNode* node) {
    DataNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}