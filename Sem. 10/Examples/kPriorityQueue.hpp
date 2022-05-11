#include <iostream>
#include "Queue.hpp"
#include <exception>
#ifndef K_PRIORITY_QUEUE
#define K_PRIORITY_QUEUE

template<typename T>
class kPriorityQueue 
{
    size_t maxPriority;
    MyQueue<T>* queues;
    void free();
    void copyFrom(const kPriorityQueue<T> &other);

    size_t elementsCount = 0;

public:
    kPriorityQueue(size_t maxPriority);
    kPriorityQueue(const kPriorityQueue<T>& other);
    kPriorityQueue<T>& operator=(const kPriorityQueue<T>& other);
    ~kPriorityQueue();

    void push(const T& obj, size_t priority);
    void push(T&& obj, size_t priority);
    void pop();

    const T& peek() const;
    bool isEmpty() const;
	
};

template<typename T>
void kPriorityQueue<T>::free() 
{
    delete[] queues;
}

template<typename T>
void kPriorityQueue<T>::copyFrom(const kPriorityQueue<T> &other) 
{
    this->maxPriority = maxPriority;
    queues = new MyQueue<T>[maxPriority];
    for (size_t i = 0; i < maxPriority; i++)
        queues[i] = other.queues[i];
}

template<typename T>
kPriorityQueue<T>::kPriorityQueue(size_t maxPriority) 
{
    if (maxPriority == 0)
        throw std::logic_error("Cannot create priority queue with no priorities");

    this->maxPriority = maxPriority;
    queues = new MyQueue<T>[maxPriority];
}

template<typename T>
kPriorityQueue<T>::kPriorityQueue(const kPriorityQueue<T> &other) 
{
    copyFrom();
}

template<typename T>
kPriorityQueue<T> &kPriorityQueue<T>::operator=(const kPriorityQueue<T> &other) 
{
    if (this != &other) 
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
kPriorityQueue<T>::~kPriorityQueue() 
{
    free();
}

template<typename T>
void kPriorityQueue<T>::push(const T &obj, size_t priority) 
{
    if (priority >= maxPriority)
        throw std::logic_error("No such priority");
    elementsCount++;
    queues[priority].push(obj);
}

template<typename T>
void kPriorityQueue<T>::push(T &&obj, size_t priority) 
{
    if (priority >= maxPriority)
        throw std::logic_error("No such priority");
    elementsCount++;
    queues[priority].push(std::move(obj));
}

template<typename T>
void kPriorityQueue<T>::pop() 
{
    
    if(isEmpty())
    throw std::logic_error("Empty queue!");
    
    for (int i = maxPriority - 1; i >= 0; i--)
    {
        if (!queues[i].isEmpty()) 
	{
            queues[i].pop();
            elementsCount--;
            return;
        }
    }
}

template<typename T>
const T& kPriorityQueue<T>::peek() const 
{

    for (int i = maxPriority - 1; i >= 0; i--)
    {
        if (!queues[i].isEmpty())
            return queues[i].peek();
    }	
  
}

template<typename T>
bool kPriorityQueue<T>::isEmpty() const 
{
    return elementsCount == 0;
}

#endif
