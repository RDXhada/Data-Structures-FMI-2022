#include <iostream>

template <typename T>
inline void Stack<T>::copy(const Stack<T>& other)
{
    size = other.size;
    capacity = other.capacity;
    value = new T[capacity];
    for (size_t i = 0; i < size; i++)
    {
        value[i] = other.value[i];
    }
}


template <typename T>
inline void Stack<T>::erase()
{
    delete[] value;
}


template <typename T>
inline void Stack<T>::resize()
{
    capacity *= 2;
    T* temp = new T[capacity];
    for (size_t i = 0; i < size; i++)
    {
        temp[i] = value[i];
    }
    
    delete[] value;
    value = temp;
}


template <typename T>
inline Stack<T>::Stack()
{
    size = 0;
    capacity = 0;
    value = new T[capacity];
}


template <typename T>
inline Stack<T>::Stack(const Stack<T>& other)
{
    copy(other);
}

template <typename T>
inline Stack<T>::~Stack()
{
    erase();
}


template <typename T>
inline Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other)
    {
        erase();
        copy(other);
    }
    return *this;
}

template <typename T>
inline bool Stack<T>::isEmpty()
{
    return size == 0;
}


template <typename T>
inline size_t Stack<T>::getSize()
{
    return size;
}


template <typename T>
inline void Stack<T>::push(const T& element)
{
    if (size == capacity)
    {
        resize();
    }
    value[size++] = element;
}

template <typename T>
inline T& Stack<T>::pop()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty, cant pop.");
    }
    return value[--size];
}

template <typename T>
inline T& Stack<T>::peek()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty, cant peek.");
    }
    return value[size - 1];
}


template <typename T>
inline T& Stack<T>::top()
{
    return value[size-1];
}


