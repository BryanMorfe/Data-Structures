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
}
