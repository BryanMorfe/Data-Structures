#ifndef BINARYNODE_H
#define BINARYNODE_H

template <class T>
class BinaryNode {
public:
    
    /** Constructors **/
    BinaryNode();
    
    BinaryNode(const T &t);
    BinaryNode(const T &t, BinaryNode<T> *ln, BinaryNode<T> *rn);
    
    /** Mutator Member Functions **/
    void setItem(const T &t);
    void setLeftNode(BinaryNode<T> *ln);
    void setRightNode(BinaryNode<T> *rn);
    
    /** Accessor Member Functions **/
    const T getItem() const;
    BinaryNode<T> *getLeftNode() const;
    BinaryNode<T> *getRightNode() const;
    
private:
    
    /** Data Members **/
    BinaryNode<T> *leftNode;
    BinaryNode<T> *rightNode;
    T item;
};

template <class T>
BinaryNode<T>::BinaryNode(): leftNode(nullptr), rightNode(nullptr), item()
{}

template <class T>
BinaryNode<T>::BinaryNode(const T &t): item(t), leftNode(nullptr), rightNode(nullptr)
{}

template <class T>
BinaryNode<T>::BinaryNode(const T &t, BinaryNode<T> *ln, BinaryNode *rn): item(t), leftNode(ln), rightNode(rn)
{}

template <class T>
void BinaryNode<T>::setItem(const T &t) {
    item = t;
}

template <class T>
void BinaryNode<T>::setLeftNode(BinaryNode<T> *ln) {
    leftNode = ln;
}

template <class T>
void BinaryNode<T>::setLeftNode(BinaryNode<T> *rn) {
    rightNode = rn;
}

template <class T>
const T BinaryNode<T>::getItem() {
    return item;
}

template <class T>
BinaryNode<T> *BinaryNode<T>::getLeftNode() {
    return leftNode;
}

template <class T>
BinaryNode<T> *BinaryNode<T>::getRightNode() {
    return rightNode;
}
