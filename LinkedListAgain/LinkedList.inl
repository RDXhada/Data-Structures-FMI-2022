#include "LinkedList.h"
#include <iostream>
#include <stack>


//ITERATOR---------------------------------------------------------
template <typename T>
inline LinkedList<T>::Iterator::Iterator(Node *ptr) : myPointer(ptr){}

template <typename T>
inline typename LinkedList<T>::Node* LinkedList<T>::Iterator::operator->()
{
    return myPointer;
}

template<typename T>
inline T LinkedList<T>::Iterator::operator*()
{
    if (myPointer == nullptr)
        throw std::runtime_error("Iterator is null.\n");
    
    return myPointer->value;
}

template<typename T>
inline typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++()
{
    if (myPointer == nullptr)
        throw std::runtime_error("Iterator is null.\n");
    
    myPointer = myPointer->next;
    return *this;
}

template<typename T>
inline typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++(int)
{
    if (myPointer == nullptr)
        throw std::runtime_error("Iterator is null.\n");
    
    Node* temp = myPointer;
    myPointer = myPointer->next;
    return temp;
}

template<typename T>
inline bool LinkedList<T>::Iterator::operator==(const Iterator& other) const
{
    return myPointer == other.myPointer;
}

template<typename T>
inline bool LinkedList<T>::Iterator::operator!=(const Iterator& other) const
{
    return myPointer != other.myPointer;
}

template <typename T>
inline typename  LinkedList<T>::Iterator LinkedList<T>::begin()
{
    return Iterator(head);
}


template <typename T>
inline typename  LinkedList<T>::Iterator LinkedList<T>::end()
{
    return Iterator();
}




//ITERATOR---------------------------------------------------------
template <typename T>
inline void LinkedList<T>::copy(const LinkedList& other)
{
    head = tail = nullptr;
    Node *current = other.head;
    while (current != nullptr)
    {
        pushBack(current->value);
        current = current->next;
    }
}

template <typename T>
inline void LinkedList<T>::swap(Node *&first, Node *&second)
{
    Node *temp = first;
    first = second;
    second = temp;
}

template <typename T>
inline void LinkedList<T>::move(LinkedList<T> &&other)
{
    swap(head, other.head);
    swap(tail, other.tail);
}


template <typename T>
inline void LinkedList<T>::clear()
{
    while (head != nullptr)
    {
        Node *current = head;
        head = head->next;
        delete current;
    }
}

//constructor
template <typename T>
inline LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

//constructor
template <typename T>
inline LinkedList<T>::LinkedList(const LinkedList &other)
{
    copy(other);
}

template<typename T>
inline LinkedList<T>::LinkedList(std::initializer_list<T> init) : LinkedList()
{
    for (auto i : init)
    {
        pushBack(i);
    }
}

//destructor
template <typename T>
inline LinkedList<T>::~LinkedList()
{
    clear();
}

//size
template <typename T>
inline const size_t LinkedList<T>::getSize() const
{
    size_t counter = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}

template <typename T>
inline void LinkedList<T>::pushFront(const T &element)
{
    Node *new_node = new Node(element);
    new_node->next = head;
    head = new_node;
}

template <typename T>
inline void LinkedList<T>::pushBack(const T &element)
{
    Node *new_node = new Node(element);
    if (head == nullptr)
    {
        head = tail = new_node;
        return;
    }
    
    tail -> next = new_node;
    tail = new_node;
}
//TODO
template <typename T>
inline void LinkedList<T>::insertAfter(Iterator position, const T &element)
{
    
}



//Да се реализира конструктор с два аргумента x и y от тип int. Конструкторът създава списък с елементи x, x + 1, ..., y, при положение, че x ≤ y.
template<typename T>
inline void LinkedList<T>::updateElement(const size_t& position, const T& element)
{
    Node* current = head;
    
    for (size_t i = 0; i < position; i++)
    {
        current = current->next;
    }
    current->value = element;
}

//Да се реализира метод l1.append(l2), която добавя към края на списъка l1 всички елементи на списъка l2.
template<typename T>
inline void LinkedList<T>::append(const LinkedList& other)
{
    if (head == nullptr)
    {
        copy(other);
        return;
    }
    
    if (other.head == nullptr)
    {
        return;
    }
    
    for (size_t i = 0; i < other.getSize(); i++)
    {
        pushBack(other[i]);
    }
}

template <typename T>
inline T LinkedList<T>::popFront()
{
    if (head == nullptr)
    {
        throw std::runtime_error("cannot delete from empty list.");
    }
    
    Node* temp = head;
    head = head->next;
    const T copy = temp->value;
    delete temp;
    return copy;
}

template <typename T>
inline T LinkedList<T>::popBack()
{
    if (head == nullptr)
    {
        throw std::runtime_error("cannot delete from empty list.");
    }
    if (head->next == nullptr)
    {
        Node* temp = head;
        
        head = tail = nullptr;
        
        const T copy = temp->value;
        delete temp;
        return copy;
    }
    
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    const T copy = temp->next->value;
    //delete last node
    delete (temp->next);
    
    temp->next = nullptr;
    return copy;
}

//TODO
template <typename T>
inline void LinkedList<T>::deleteAfter(Iterator position)
{
    
}
//TODO
template <typename T>
inline void LinkedList<T>::removeElement(const size_t &position)
{
}

//algorythyms
template <typename T>
inline T LinkedList<T>::listSum()
{
    Node *current = head;
    int sum = 0;
    while (current != nullptr)
    {
        sum += current->value;
        current = current->next;
    }
    return sum;
}

template <typename T>
inline void LinkedList<T>::sort()
{
    Node *current = head;
    Node *min = current;
    Node *innerNode;
    while (current != nullptr)
    {
        innerNode = current->next;
        while (innerNode!=nullptr)
        {
            if (innerNode->value < min->value)
            {
                min = innerNode;
            }
            innerNode = innerNode->next;
        }
        if (current!=min)
        {
            std::swap(current->value, min->value);
        }
        current = current->next;
        min = current;
    }
}

template <typename T>
inline void LinkedList<T>::reverse()
{
    Node *current = head;
    Node *previous = nullptr;
    Node *next1 = nullptr;
    
    while (current != nullptr)
    {
        next1 = current->next;
        current->next = previous;
        previous = current;
        current = next1;
    }
    head = previous;
}



template <typename T>
inline T LinkedList<T>::getFirst()
{
    return head->value;
}

template <typename T>
inline T LinkedList<T>::getLast()
{
    return tail->value;
}

//Да се напише фунцкия bool palindrom (...), която проверява дали e palindrome
template <typename T>
inline bool LinkedList<T>::palindrom()
{
    
    Node* current = head;
    std::stack<int> stack1;
    while (current != nullptr)
    {
        stack1.push(current->value);
        current = current->next;
    }
    
    while (head != nullptr)
    {
        int i = stack1.top();
        stack1.pop();
        if (head->value != i)
        {
            return false;
        }
        head = head->next;
    }
    
    return true;
}


//Да се напише фунцкия bool issorted (...), която проверява дали елементите на даден контейнер са подредени в нарастващ или в намаляващ ред.
template <typename T>
inline bool LinkedList<T>::issorted()
{
    if (head == nullptr) {
        return true;
    }
    
    for (Node *temp = head; temp->next != nullptr; temp = temp->next) {
        if (temp->value >= temp->next->value && temp->value <= temp->next->value)
        {
            return false;
        }
    }
    return true;
}


//Да се напише функция bool duplicates (...), която проверява дали в
//    контейнер има дублиращи се елементи.
template <typename T>
inline void LinkedList<T>::removeDuplicates()
{
    if (head == nullptr)
    {
        throw std::runtime_error("Cannot remove duplicates from empty list.");
    }
    Node *current = head;
    Node *temp;
    while(current->next != nullptr)
    {
        if (current->value == current->next->value)
        {
            temp = current->next->next;
            delete current->next;
            current->next = temp;
        }
        else
        {
            current = current->next;
        }
    }
}


template <typename T>
inline T LinkedList<T>::search(const T& X)
{
    int index = 0;
    Node *temp = head;
    
    while(temp!= nullptr){
        if(temp->value == X){
            //If element found return index
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}



template <typename T>
inline T LinkedList<T>::operator[](const size_t &position) const
{
    Node *current = head;
    size_t counter = position;
    while (current != nullptr && counter --> 0)
    {
        current = current->next;
    }
    
    if(current == nullptr)
    {
        return T();
    }
    else { return current->value; }
}

template <typename T>
inline void LinkedList<T>::print()
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
}












