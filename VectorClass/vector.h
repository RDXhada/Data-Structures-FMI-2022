#ifndef vector_h
#define vector_h


template <typename T>
class Vector
{
private:
    T *value;
    size_t capacity;
    size_t size;
    
    
    void copy(const Vector<T>& other);
    void resize();
    void erase();
public:
    Vector();
    Vector(size_t capacity);
    Vector(const T *value, size_t size, size_t capacity);
    Vector(const Vector<T>& other);
    ~Vector();
    
    
    const size_t getSize() const;
    const size_t getCapacity() const;
    void pushBack(const T element);
    void popBack();
    void popAt(const size_t& position);
    void updateAt(const size_t& position, const T& element);
    bool doesExist(const T& X);
    bool isEmpty();
    
    Vector<T>& operator=(const Vector<T>& other);
    T& operator[](const size_t& position) const;
};


#include "vector.inl"
#endif /* vector_h */
