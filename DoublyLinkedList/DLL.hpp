//
//  DLL.h
//  week3and4
//
//  Created by Dzhem Shenolov on 23.10.22.
//

#ifndef DLL_h
#define DLL_h
#include <iostream>


template <typename T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T value_;
        Node *previous_;
        Node *next_;
        Node(const T& value, Node *previous = nullptr, Node *next = nullptr);
        Node() : value_(0), next_(nullptr) {}
        Node(int x) : value_(x), next_(nullptr) {}
        Node(int x, Node *next_) : value_(x), next_(next_) {}
    };
    
    Node *head;
    Node *tail;
    size_t size;
    //copy
    void copy(const DoublyLinkedList &other);
    //delete
    void deleteDoublyList();
public:
//Const Iterator----------------------------------------------------
    class constIterator
    {
    public:
        friend class DoublyLinkedList;
        //constructors
        constIterator(Node *ptr);
        constIterator();
        
        //operators
        bool operator==(const constIterator& other) const;
        bool operator!=(const constIterator& other) const;
        const T* operator->() const;
        const T& operator*() const;
        constIterator operator++(int);
        constIterator& operator++();
        constIterator operator--(int);
        constIterator& operator--();
        
    protected:
        Node *myPointer;
        };
//Const iterator(end) ------------------------------------------------
//ITERATOR
    class Iterator : public constIterator
    {
    public:
        friend class DoublyLinkedList;
        Iterator(Node *ptr = nullptr);
        
        T& operator*();
        T* operator->();
        
        Iterator begin();
        Iterator end();
        
        Iterator insert(Iterator position, const T& new_value);
        Iterator erase(Iterator position);
    };
public:
    
    
    //constructors and destructors
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList &other);
    ~DoublyLinkedList();
    
    //insert
    void pushFront(const T& new_value);
    void insertLast(const T& new_value);
    void insertAfter(Node *iterator,const T& new_value);
    
    //operator
    DoublyLinkedList& operator=(const DoublyLinkedList& other);
    
    //delete
    T deleteFirst();
    void deleteLast();
    T deleteAfter(Iterator iterator);
    
    //functions
    //TODO
    DoublyLinkedList<T>& sort();
    DoublyLinkedList<T>& mergeSort();
    
    
    //actions
    T GetNth(int index);
    std::vector<T> toVector();
    size_t getSize();
    void clear();
    void print();
};

#include "DLL.inl"
#endif /* DLL_h */
