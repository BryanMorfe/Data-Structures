#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "../../BinaryNode.h"

template <class T>
class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(const T &item);
    void addElement(const T &item);
    void inOrderDisplay();
    void preOrderDisplay();
    void postOrderDisplay();
    void levelOrderDisplay();
    BinaryNode<T> *breathFirstSearch(const T &item);
    BinaryNode<T> *depthFirstSearch(const T &item);
    T & removeBFS();
    T & removeDFS();
    void removeBFS(const T &item);
    void removeDFS(const T &item);
private:
    BinaryNode<T> *root;
    int count;
};
