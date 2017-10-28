#ifndef LINEARNODE_H
#define LINEARNODE_H

template <class T>
class LinearNode {
public:
    LinearNode();
    LinearNode(const T t);
    LinearNode(const T t, LinearNode<T> *next);
    void setItem(const T &t);
    void setNextNode(LinearNode<T> *next);
    const T getItem() const;
    LinearNode<T>* getNextNode() const;
private:
    T item;
    LinearNode<T> *nextNode;
};

template <class T>
LinearNode<T>::LinearNode(): item(), nextNode(nullptr)
{}

template <class T>
LinearNode<T>::LinearNode(const T t): item(t), nextNode(nullptr)
{}

template <class T>
LinearNode<T>::LinearNode(const T t, Node<T> *next): item(t), nextNode(next)
{}

template <class T>
void LinearNode<T>::setItem(const T &t) { item = t; }

template <class T>
void LinearNode<T>::setNextNode(Node<T> *next) { nextNode = next; }

template <class T>
const T LinearNode<T>::getItem() const { return item; }

template <class T>
LinearNode<T>* LinearNode<T>::getNextNode() const { return nextNode; }

#endif
