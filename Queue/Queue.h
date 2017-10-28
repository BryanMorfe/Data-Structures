#ifndef QUEUE_H
#define QUEUE_H
#include "../LinearNode.h"

template <class T>
class Queue {
public:
    Queue();
    Queue(T item);
    ~Queue();
    void enqueue(T item);
    T dequeue();
    T peek();
    int count();
    bool isEmpty();
private:
    LinearNode<T> *headNode;
    LinearNode<T> *backNode;
    int Count;
};

template <class T>
Queue<T>::Queue(): Count(0), headNode(nullptr), backNode(nullptr)
{}

template <class T>
Queue<T>::Queue(T item) {
    LinearNode<T> *ptr = new LinearNode<T>(item);
    headNode = ptr;
    backNode = ptr;
    Count = 1;
}

template <class T>
Queue<T>::~Queue() {
    while (Count > 0) dequeue();
}

template <class T>
void Queue<T>::enqueue(T item) {
    LinearNode<T> *ptr = new LinearNode<T>(item);
    if (backNode != nullptr) {
        backNode->setNextNode(ptr);
        backNode = ptr;
    } else {
        headNode = ptr;
        backNode = ptr;
    }
    
    Count++;
}

template <class T>
T Queue<T>::dequeue() {
    if (headNode != nullptr) {
        
        if (headNode->getNextNode() != nullptr) {
            LinearNode<T> *tmp = headNode->getNextNode();
            T t = headNode->getItem();
            delete headNode;
            headNode = tmp;
            Count--;
            return t;
            
        } else {
            T t = headNode->getItem();
            delete headNode;
            headNode = nullptr;
            backNode = nullptr;
            Count--;
            return t;
        }
        
    } else {
        std::cout << "Attempt to dequeue on empty queue." << std::endl;
        exit(1);
    }
    
}

template <class T>
T Queue<T>::peek() {
    
    if (isEmpty()) {
        std::cout << "Attempt to peek on empty queue." << std::endl;
        exit(1);
    }
    
    return headNode->getItem();
}

template <class T>
int Queue<T>::count() { return Count; }

template <class T>
bool Queue<T>::isEmpty() {
    return Count == 0;
}

#endif
