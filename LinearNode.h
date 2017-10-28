#ifndef LINEARNODE_H
#define LINEARNODE_H

template <class T>
class LinearNode {
public:
    
    /** Constructors **/
    LinearNode();
    // Postcondition: Creates a linear node that points to no other node, and item is default.
    
    LinearNode(const T t);
    // Postcondition: Creates a linear node that points to no other node and item = t.
    
    LinearNode(const T t, LinearNode<T> *next);
    // Postcondition: Creates a linear node that points to "next" and item = t.
    
    void setItem(const T &t);
    // Postcondition: Assings t to the data member "item".
    
    void setNextNode(LinearNode<T> *next);
    // Postcondition: Sets the "nextNode" to "next".
    
    const T getItem() const;
    // Postcondition: Returns the value of "item".
    
    LinearNode<T>* getNextNode() const;
    // Postcondition: Returns the address of the node this obj points to, if any.
    
private:
    T item;                     // The value associated to the node.
    LinearNode<T> *nextNode;    // The node that this node obj points to.
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
