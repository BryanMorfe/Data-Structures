#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template<class T>
class Stack
{
public:
    Stack();
    Stack(size_t n);
    Stack(size_t n, const T &repeatItem);
    Stack(const Stack &other);
    ~Stack();
    
    T top() const;
    T bottom() const;
    
    T pop();
    void push(const T &item);
    
    Stack<T> &operator=(const Stack &other);
    
    size_t size() const;
    
private:
    void allocate();
    
    size_t count;
    T *data;
    size_t capacity;

};

template<class T>
Stack<T>::Stack(): count(0), capacity(10)
{
    data = new T[10];
}

template<class T>
Stack<T>::Stack(size_t n): count(n), capacity(n)
{
    data = new T[n];
}

template<class T>
Stack<T>::Stack(size_t n, const T &repeatItem): Stack(n)
{
    for (size_t i = 0; i < n; i++) data[i] = repeatItem;
}

template<class T>
Stack<T>::Stack(const Stack &other): count(other.count), capacity(other.capacity)
{
    data = new T[capacity];
    memcpy(data, other.data, count);
}

template<class T>
Stack<T>::~Stack()
{
    delete []data;
}

template<class T>
T Stack<T>::top() const
{
    if (count == 0)
        throw logic_error("Calling top on an empty stack!");
    
    return data[count - 1];
}

template<class T>
T Stack<T>::bottom() const
{
    if (count == 0)
        throw logic_error("Calling bottom on an empty stack!");
    
    return data[0];
}

template<class T>
T Stack<T>::pop()
{
    if (count == 0)
        throw logic_error("Trying to pop from an empty stack!");
    
    count--;
    
    return data[count];
}

template<class T>
void Stack<T>::push(const T &item)
{
    
    if (count >= capacity)
        allocate();
    
    data[count++] = item;
}

template<class T>
Stack<T> &Stack<T>::operator=(const Stack &other)
{
    count = other.count;
    capacity = other.capacity;
    delete [] data;
    data = new T[count];
    memcpy(data, other.data, count);
}

template<class T>
size_t Stack<T>::size() const
{
    return count;
}

template<class T>
void Stack<T>::allocate()
{
    T *temp = data;
    capacity *= 2;
    data = new T[capacity];
    memcpy(data, temp, count);
    delete [] temp;
}

#endif /* STACK_H */
