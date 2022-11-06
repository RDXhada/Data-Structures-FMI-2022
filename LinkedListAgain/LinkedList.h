#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include <vector>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T value;
        Node *next;
        Node(const T& value, Node *next = nullptr) : value(value), next(next) {}
    };
    
    Node *head;
    Node *tail;
    void copy(const LinkedList &other);
    void swap(Node *&first, Node *&second);
    void move(LinkedList<T> &&other);
    void clear();
//Iterator---------------------------------
public:
    class Iterator
    {
    private:
        Node *myPointer;
    public:
        Iterator() = default;
        Iterator(Node *ptr);
        Iterator& operator++();
        Iterator& operator++(int);
        
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        
        Node* operator->();
        T operator*();
    };
//Iterator---------------------------------
public:
    LinkedList();
    LinkedList(const LinkedList& other);
    explicit LinkedList(std::initializer_list<T> initList);
    ~LinkedList();
    
    //get lenght
    const size_t getSize() const;
    //push
    void pushFront(const T& element);
    void pushBack(const T& element);
    //TODO
    void insertAfter(Iterator position, const T& element);
    void updateElement(const size_t& position,const T& element);
    void append(const LinkedList& other);
    
    //pop
    T popFront();
    T popBack();
    //TODO
    void deleteAfter(Iterator position);
    //TODO
    void removeElement(const size_t& position);
    
    //algorithms
    T listSum();
    void sort();
    void reverse();
    T getFirst();
    T getLast();
    bool palindrom();
    bool issortedAscending();
    bool issortedDescending();
    void removeDuplicates();
    T search(const T& X);
    //operator
    T operator[](const size_t& position) const;
    

    void print();
    
    //Iterator
    Iterator begin();
    Iterator end();
    
    //to vector
    std::vector<int> to_vector()
    {
         Node* current = head;
         std::vector<int> vec;
         while (current != nullptr)
         {
             vec.push_back(current->value);
             current = current->next;
         }
         return vec;
     }
    
};

#include "LinkedList.inl"
#endif /* LinkedList_h */
