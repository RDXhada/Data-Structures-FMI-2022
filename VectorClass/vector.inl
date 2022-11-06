template <typename T>
inline void Vector<T>::copy(const Vector<T> &other)
{
    value = new T[other.capacity];
    for (size_t i = 0; i < size; i++)
    {
        value[i] = other.value[i];
    }
    capacity = other.capacity;
    size = other.size;
}

template <typename T>
inline void Vector<T>::resize()
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
inline void Vector<T>::erase()
{
    delete[] value;
}

template <typename T>
inline Vector<T>::Vector() : size(0), capacity(2) { value = new T[capacity];}


template <typename T>
inline Vector<T>::Vector(size_t capacity) : size(0), capacity(capacity)
{
    value = new T[capacity];
}

template <typename T>
inline Vector<T>::Vector(const T *value, size_t size, size_t capacity) : size(size), capacity(capacity)
{
    value = new T[capacity];
    for (size_t i = 0; i < size; i++)
    {
        value[i] = value[i];
    }
}

template <typename T>
inline Vector<T>::Vector(const Vector<T>& other)
{
    if (this != &other)
    {
        erase();
        copy(other);
    }
    return *this;
}

template <typename T>
inline Vector<T>::~Vector()
{
    erase();
}


template<typename T>
const size_t Vector<T>::getSize() const
{
    return size;
}

template<typename T>
const size_t Vector<T>::getCapacity() const
{
    return capacity;
}

template<typename T>
void Vector<T>::pushBack(const T element)
{
    if (size >= capacity)
    {
        resize();
    }
    value[size++] = element;
}

template<typename T>
inline void Vector<T>::popBack()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty, cant pop.");
    }
    return value[--size];
}

template <typename T>
inline bool Vector<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
inline void Vector<T>::popAt(const size_t& position)
{
    if (position >= size)
    {
        throw std::runtime_error("Index to remove out of bounds.\n");
    }
    
    if (position == size-1)
    {
        popBack();
        return;
    }
    
    value[position].~T();
    for (size_t i = position; i < size - 1; i++)
    {
        value[i] = value[i + 1];
    }
    --size;
}

template <typename T>
inline void Vector<T>::updateAt(const size_t& position, const T &element)
{
    
    if (position >= size)
    {
        throw std::runtime_error("Index to update out of bounds.\n");
    }
    value[position] = element;
}

template <typename T>
inline bool Vector<T>::doesExist(const T &X)
{
    for (size_t i = 0; i < size; i++)
    {
        if (X == value[i])
        {
            return true;
        }
    }
    return false;
}

template <typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T> &other)
{
    if (this == &other)
    {
        return *this;
    }
    
    delete[] value;
    copy(other);
    return *this;
}


template<typename T>
inline T& Vector<T>::operator[](const size_t& position) const
{
    if (index >= size)
    {
        throw std::runtime_error("Index out of range");
    }

    return value[position];
}
