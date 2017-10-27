#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
    Node();
    Node(const T t);
    Node(const T t, Node<T> *next);
    void setItem(const T &t);
    void setNextNode(Node<T> *next);
    const T getItem() const;
    Node<T>* getNextNode() const;
private:
    T item;
    Node<T> *nextNode;
};

template <class T>
Node<T>::Node(): item(), nextNode(nullptr)
{}

template <class T>
Node<T>::Node(const T t): item(t), nextNode(nullptr)
{}

template <class T>
Node<T>::Node(const T t, Node<T> *next): item(t), nextNode(next)
{}

template <class T>
void Node<T>::setItem(const T &t) { item = t; }

template <class T>
void Node<T>::setNextNode(Node<T> *next) { nextNode = next; }

template <class T>
const T Node<T>::getItem() const { return item; }

template <class T>
Node<T>* Node<T>::getNextNode() const { return nextNode; }

#endif
