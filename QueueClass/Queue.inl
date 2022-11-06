#include <iostream>

template <typename T>
inline void Queue<T>::copy(const Queue<T>& other)
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
inline void Queue<T>::erase()
{
    delete[] value;
}

template <typename T>
inline void Queue<T>::resize() {
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
inline Queue<T>::Queue()
{
    size = 0;
    capacity = 0;
    value = new T[capacity];
}

template <typename T>
inline Queue<T>::Queue(const Queue<T>& other)
{
    copy(other);
}

template <typename T>
inline Queue<T>::~Queue()
{
    erase();
}

template <typename T>
inline Queue<T>& Queue<T>::operator=(const Queue<T> &other)
{
    if (this != &other)
    {
        erase();
        copy(other);
    }
    
    return *this;
}

template <typename T>
inline void Queue<T>::push(const T& element)
{
    if (size == capacity)
    {
        resize();
    }
    
    value[size++] = element;
}


template <typename T>
inline void Queue<T>::pop()
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty. Can't pop front.");
    }
    
    for (size_t i = 0; i < size-1; i++)
    {
        value[i] = value[i+1];
        
    }
    size--;
}

template <typename T>
inline T& Queue<T>::front()
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty, cant get front");
    }
    return value[0];
}

template <typename T>
inline T& Queue<T>::back()
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty, cant get front");
    }
    return value[size-1];
}



template <typename T>
inline size_t Queue<T>::getSize()
{
    return size;
}


template <typename T>
inline bool Queue<T>::isEmpty()
{
    return size==0;
}


