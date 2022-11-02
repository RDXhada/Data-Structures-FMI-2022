#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h
#include <iostream>
#include <vector>

template <typename T>
class DoublyLinkedList
{
private:
  struct Node{
      T value;
      Node *next;
      Node *prev;
      
      Node(const T& value,Node *prev = nullptr,Node *next = nullptr) : value(value), prev(prev), next(next) {}
      
  };
    Node *head;
    Node *tail;
    void copy(const DoublyLinkedList& other);
public:
    class Iterator;
    
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& other);
    ~DoublyLinkedList();
    const size_t getSize() const;
        
    //modify
    DoublyLinkedList<T>& pushFirst(const T& element);
    DoublyLinkedList<T>& pushLast(const T& element);
    DoublyLinkedList<T>& popFirst();
    DoublyLinkedList<T>& popLast();
    DoublyLinkedList<T>& removeElement(int position);
    
    //operations
    void reverse();
    //bubble sort O(n^2)
    void sort();
    
    
    //update
    void update(const size_t& position, const T& element);
    
    //toVector
    std::vector<T> toVector();
    void clear();
    //print
    void print();
    
public:
    class Iterator
    {
    private:
        Node *myPointer;
        Iterator(Node *newPtr) : myPointer(newPtr) {}
    public:
        friend class DoublyLinkedList;
        Iterator() : myPointer(nullptr) {}
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        bool operator==(const Iterator& rhs) const;
        bool operator!=(const Iterator& rhs) const;
        T& operator*();
        T* operator->();
    };
    Iterator begin() {return Iterator(head);}
    Iterator end() {return Iterator(tail);}
    
    
};


#include "inlineDLL.inl"
#endif /* DoublyLinkedList_h */
