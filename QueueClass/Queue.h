#ifndef Queue_h
#define Queue_h
#include <iostream>


template <typename T>
class Queue
{
private:
    T* value;
    size_t capacity;
    size_t size;
    
private:
    void copy(const Queue<T>& other);
    void erase();
    void resize();
public:
    Queue();
    Queue(const Queue<T>& other);
    ~Queue();
    

    Queue& operator=(const Queue<T>& other);
    void push(const T& element);
    void pop();
    T& front();
    T& back();
    size_t getSize();
    bool isEmpty();


};


#include "Queue.inl"
#endif
