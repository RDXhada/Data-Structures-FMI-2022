#include <iostream>
#include <vector>
#include <cassert>
#include "DLL.hpp"

//node
template <typename T>
inline DoublyLinkedList<T>::Node::Node(const T& value, Node *next, Node *previous)
{
    value_ = value;
    next_ = next;
    previous_ = previous;
}


//constructor
template <typename T>
inline DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

//copy
template <typename T>
inline void DoublyLinkedList<T>::copy(const DoublyLinkedList<T> &otherList)
{
    if (otherList.head == nullptr)
    {
        head = tail = nullptr;
    }
    else
    {
        head = new Node (otherList.head);
        Node *temp = head;
        Node *otherTemp = otherList.head -> next_;
        while (otherTemp != nullptr) {
            temp->next = new Node (otherTemp, nullptr,temp);
            temp = temp->next_;
            otherTemp = otherTemp->next_;
        }
        tail = temp;
    }
}
//copy
template <typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &other) { copy(other); }


//destructor
template <typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
    delete head;
    delete tail;
}

//operator=
template <typename T>
inline DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}




//pushFront
template <typename T>
inline void DoublyLinkedList<T>::pushFront(const T &new_value)
{
    Node *new_node = new Node();
    new_node->value_ = new_value;
    
    new_node->next_ = head;
    new_node->previous_ = nullptr;
    if (head != nullptr)
    {
        head->previous_ = new_node;
    }
    head = new_node;
}

//pushBack
template <typename T>
inline void DoublyLinkedList<T>::insertLast(const T& new_value)
{    
    Node *new_node= new Node(new_value, nullptr, nullptr);
    new_node->value_ = new_value;
    new_node->next_ = nullptr;
    Node *temp = head;
    if (head == nullptr) {
        new_node->previous_ = nullptr;
        head = new_node;
        return;
    }
    while (temp->next_ != nullptr) {
        temp = temp->next_;
    }
    
    temp->next_ = new_node;
    new_node->previous_ = temp;
    
}

//insert After
template <typename T>
inline void DoublyLinkedList<T>::insertAfter(Node *iterator,const T& new_value)
{
    if (iterator == nullptr) {
        return;
    }
    Node *new_node = new Node();
    new_node->value_ = new_value;
    new_node->next_ = iterator->next_;
    iterator->next_ = new_node;
    new_node->previous_ = iterator;
    if (new_node->next_ != nullptr)
    {
        new_node->next_->previous_ = new_node;
    }
}


//delete first
template <typename T>
inline T DoublyLinkedList<T>::deleteFirst()
{
    if (head == nullptr) {
        throw std::invalid_argument( "Cannot remove from empty list." );
    }
    
    Node* temp = head;
    head = head->next_;
    int value = temp->value_;
    delete temp;
    
    return value;
}

template <typename T>
inline void DoublyLinkedList<T>::deleteLast()
{
    if (head == nullptr) {
        throw std::invalid_argument( "Removing element from an empty list." );
    }
    if (head -> next_ == nullptr) {
        head = nullptr;
    }
    else
    {
        Node *temp = head;
        while (temp->next_->next_ != nullptr)
        {
            temp = temp->next_;
        }
        
        Node *lastNode = temp->next_;
        temp->next_ = nullptr;
        std::free(lastNode);
    }
    
}

template <typename T>
inline T DoublyLinkedList<T>::deleteAfter(Iterator iterator)
{
    if (head == nullptr) {
        throw std::runtime_error("Cannot delete from empty list.");
    }
    if (iterator == nullptr || iterator->next_ == nullptr) {
        throw std::runtime_error("Cannot find element to remove.");
    }
    Node *temp = iterator->next_;
    iterator->next_ = temp->next_;
    if (tail == temp) {
        tail = iterator;
    }
    int value = temp->value_;
    delete temp;
    return value;
    
}

//get the element by a given position
template<typename T>
inline T DoublyLinkedList<T>::GetNth(int index)
{
 
    Node* current = head;
    int counter = 0;
    while (current != NULL) {
        if (counter == index)
            return (current->value_);
        counter++;
        current = current->next_;
    }
 
    assert(0);
}


template<typename T>
inline std::vector<T> DoublyLinkedList<T>::toVector()
{
    Node* current = head;
    std::vector<T> vect;
    
    while (current != nullptr)
    {
        vect.push_back(current->value_);
        current = current->next_;
    }

    return vect;
}

//clear
template <typename T>
inline void DoublyLinkedList<T>::clear()
{
    Node *current = head;
    while (current != nullptr) {
        Node *deleteElement = current;
        current = current->next_;
        delete deleteElement;
    }
    head = tail = nullptr;
}

//getSie
template <typename T>
inline size_t DoublyLinkedList<T>::getSize()
{
    size_t size = 0;
    Node *temp = head;
    while(temp!=nullptr)
    {
        size++;
        temp = temp->next_;
        
    }
    return size;
}

//print
template <typename T>
inline void DoublyLinkedList<T>::print()
{
    Node* node = head;
    while (node != nullptr)
    {
        std::cout << " " << node -> value_;
        node = node -> next_;
    }
}

//Const Iterator ---------------------------------------------------------------------------
template <typename T>
inline DoublyLinkedList<T>::constIterator::constIterator(Node *ptr) : myPointer(ptr) {}

template <typename T>
inline DoublyLinkedList<T>::constIterator::constIterator() : myPointer(nullptr) {}

template <typename T>
inline bool DoublyLinkedList<T>::constIterator::operator==(const constIterator &other) const
{
    return myPointer == other.myPointer;
}

template <typename T>
inline bool DoublyLinkedList<T>::constIterator::operator!=(const constIterator &other) const
{
    return myPointer != other.myPointer;
}

template <typename T>
inline const T* DoublyLinkedList<T>::constIterator::operator->() const
{
    return &myPointer->value_;
}


template <typename T>
inline const T& DoublyLinkedList<T>::constIterator::operator*() const
{
    return myPointer->value_;
}

template <typename T>
inline typename DoublyLinkedList<T>::constIterator DoublyLinkedList<T>::constIterator::operator++(int)
{
    constIterator temp = *this;
    myPointer = myPointer->next_;
    return temp;
}

template <typename T>
inline typename DoublyLinkedList<T>::constIterator& DoublyLinkedList<T>::constIterator::operator++()
{
    constIterator temp = *this;
    myPointer = myPointer->next_;
    return temp;
}

template <typename T>
inline typename DoublyLinkedList<T>::constIterator DoublyLinkedList<T>::constIterator::operator--(int)
{
    constIterator temp = *this;
    --(*this);
    return temp;
}

template <typename T>
inline typename DoublyLinkedList<T>::constIterator& DoublyLinkedList<T>::constIterator::operator--()
{
    constIterator temp = *this;
    myPointer = myPointer->previous_;
    return temp;
}

// Iterator ---------------------------------------------------------------------------
template <typename T>
inline T& DoublyLinkedList<T>::Iterator::operator*()
{
    return constIterator::myPointer->value_;
}

template <typename T>
inline T* DoublyLinkedList<T>::Iterator::operator->()
{
    return &constIterator::myPointer->value_;
}

template <typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::begin()
{
    return Iterator(head);
}

template <typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::end()
{
    return Iterator(tail);
}

template <typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::insert(Iterator position, const T& new_value)
{
    Node *new_node = new Node(new_value, position.constIterator::myPointer->next_);
    if (position.constIterator::myPointer->next_ == tail)
    {
        tail = new_node;
    }
    position.constIterator::myPointer->next_ = new_node;
    return position;
}

template <typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::erase(Iterator position)
{
    Node *nodeToDelete = position.constIterator::myPointer->next_;
    position.constIterator::myPointer->next_ = position.constIterator::myPointer->next_->next_;
    if (nodeToDelete == tail)
    {
        tail = position.constIterator::myPointer;
    }
    delete nodeToDelete;
    return position;
}




















