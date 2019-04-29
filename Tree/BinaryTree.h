#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "../BinaryNode.h"
#include <iostream>

template <class T>
class BinaryTree {
public:
    BinaryTree();
    BinaryTree(const T &item);
    void insert(const T &item);
    void inOrderDisplay() const;
    void preOrderDisplay() const;
    void postOrderDisplay() const;
    void levelOrderDisplay() const;
    BinaryNode<T> * const breadthFirstSearch(const T &item) const;
    BinaryNode<T> * const depthFirstSearch(const T &item) const;
    T & removeBFS();
    T & removeDFS();
    void removeBFS(const T &item);
    void removeDFS(const T &item);
    int size() const;
    ~BinaryTree();
private:
    BinaryNode<T> *root;
    int count;
};

template <class T>
BinaryTree<T>::BinaryTree(): root(nullptr), count(0) {}

template <class T>
BinaryTree<T>::BinaryTree(const T &item): root(new BinaryNode<T>(item)), count(1) {}

template <class T>
void BinaryTree<T>::insert(const T &item) {
    if (root == nullptr)
        root = new BinaryNode<T>(item);
    else {
        BinaryNode<T> *temp = root;
        
        if (root->getRightNode() == nullptr) {
            root = root->getLeftNode();
            insert(item);
        } else {
            root = root->getRightNode();
            insert(item);
        }
        
        root = temp;
    }
    count++;
}

template <class T>
void BinaryTree<T>::inOrderDisplay() {
    if (root != nullptr) {
        BinaryNode<T> *temp = root;
        root = root->getLeftNode();
        inOrderDisplay();
        std::cout << temp->getItem() << std::endl;
        root = root->getRightNode();
        inOrderDisplay();
        root = temp;
    }
}

template <class T>
void BinaryTree<T>::preOrderDisplay() {
    if (root != nullptr) {
        std::cout << temp->getItem() << std::endl;
        BinaryNode<T> *temp = root;
        root = root->getLeftNode();
        preOrderDisplay();
        root = root->getRightNode();
        preOrderDisplay();
        root = temp;
    }
}

template <class T>
void BinaryTree<T>::postOrderDisplay() {
    if (root != nullptr) {
        BinaryNode<T> *temp = root;
        root = root->getLeftNode();
        postOrderDisplay();
        root = root->getRightNode();
        postOrderDisplay();
        root = temp;
        std::cout << root->getItem() << std::endl;
    }
}

template <class T>
void BinaryTree<T>::levelOrderDisplay() {
    if (root != nullptr) {
        BinaryNode<T> *temp = root;
        root = root->getLeftNode();
        postOrderDisplay();
        root = root->getRightNode();
        postOrderDisplay();
        root = temp;
        std::cout << root->getItem() << std::endl;
    }
}

template <class T>
BinaryNode<T> * const BinaryTree<T>::breadthFirstSearch(const T &item) {
    
}

template <class T>
BinaryNode<T> * const BinaryTree<T>::depthFirstSearch(const T &item) {
    if (root != nullptr) {
        BinaryNode<T> *temp = root;
        
        if (root->getItem() == item)
            return root;
        
        root->getLeftNode(); //finish
        depthFirstSearch(item);
    }
    
    return nullptr;
}
