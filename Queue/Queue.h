#ifndef QUEUE_H
#define QUEUE_H
#include "../LinearNode.h"

template <class T>
class Queue {
public:
    
    /** Constructors & Destructor **/
    Queue();
    // Postcondition: Intializes the queue with no elements and no head or back node.
    
    Queue(T item);
    // Postcondition: Intializes the queue with one element T and sets it as head and back node.
    
    ~Queue();
    // Postcondition: Eliminates all the nodes and frees up allocated memory.
    
    /** Memeber Functions **/
    void enqueue(T item);
    // Postcondition: Creates a new node with item t.
    
    T dequeue();
    // Precondition: The queue must have at least one node.
    // Postcondition: Eliminates the next node in queue and returns the T element.
    
    T peek();
    // Precondition: The queue must have at least one node.
    // Postcondition: Returns the next element in queue.
    
    int count();
    // Postcondition: Returns the size of the Queue.
    
    bool isEmpty();
    // Postcondition: Returns the true if queue is empty, otherwise false.
    
private:
    
    /** Data Memebers **/
    LinearNode<T> *headNode;    // The head LinearNode (next in queue).
    LinearNode<T> *backNode;    // The last LinearNode in queue.
    int Count;                  // The number of nodes in the queue.
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
