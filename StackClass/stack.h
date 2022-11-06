#ifndef stack_h
#define stack_h


template <typename T>
class Stack
{
private:
    size_t size;
    size_t capacity;
    T* value;
    
    void copy(const Stack<T>& other);
    void erase();
    void resize();
public:
    Stack();
    Stack(const Stack<T>& other);
    ~Stack();
    
    
    Stack<T>& operator=(const Stack<T>& other);
    bool isEmpty();
    size_t getSize();
    T& top();
    void push(const T& element);
    T& peek();
    T& pop();
};



#include "stack.inl"
#endif
