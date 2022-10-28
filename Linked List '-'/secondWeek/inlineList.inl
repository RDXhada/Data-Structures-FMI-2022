#include <iostream>
#include <stack>
#include "LinkedList.hpp"

//nodes
template <typename T>
inline LinkedList<T>::Node::Node(const T& value, Node *next)
{
    value_ = value;
    next_ = next;
}

//copy
template <typename T>
inline void LinkedList<T>::copy(const LinkedList& other)
{
    size = 0;
    head = tail = nullptr;
    
    Node* current = other.head;
    while (current)
    {
        push(current->value_);
        current = current->next_;
    }
}

template <typename T>
inline void LinkedList<T>::swap(Node *&first, Node *&second)
{
    Node *temp =  first;
    first = second;
    second = temp;
}

template <typename T>
inline void LinkedList<T>::move(LinkedList<T> &&other)
{
    swap(head, other.head);
    swap(tail, other.tail);
}

//delete
template <typename T>
inline  void LinkedList<T>::delete_()
{
    while (head != nullptr)
    {
        Node *current = head;
        head = head->next_;
        delete current;
    }
}

//constructor
template <typename T>
inline LinkedList<T>::LinkedList() : head(), tail(), size(0) {}
//template <typename T>
//inline LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}


//copy list
template <typename T>
inline LinkedList<T>::LinkedList(const LinkedList &other)
{
    copy(other);
}

//delete list/destructor
template <typename T>
inline LinkedList<T>::~LinkedList()
{
    delete_();
}

//Да се реализира метод int LList::count(int x), който преброява колко пъти елементът x се среща в списъка.
template <typename T>
inline size_t LinkedList<T>::count(const T& element) const
{
    size_t elemAmountInList = 0;
    Node* current = head;
    while (current != nullptr)
    {
        if (element == current->value_)
            elemAmountInList++;
        current = current->next_;
    }
    
    return elemAmountInList;
}

//Да се реализира конструктор с два аргумента x и y от тип int. Конструкторът създава списък с елементи x, x + 1, ..., y, при положение, че x ≤ y.
template<typename T>
inline void LinkedList<T>::updateAt(const size_t& index, const T& elem)
{
    Node* current = head;
    
    for (size_t i = 0; i < index; i++)
        current = current->next_;
    current->data_ = elem;
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
        return;
    
    for (size_t i = 0; i < other.getSize(); i++)
        push(other[i]);
}

//get the size of list
template<typename T>
inline const size_t LinkedList<T>::getSize() const
{
    size_t count = 0;
    
    Node* current = head;
    while (current != nullptr)
    {
        current = current->next_;
        count++;
    }
    
    return count;
}


//Да се реализира метод LList::push_back за добавяне на елемент от тип T към края на списъка.
template <typename T>
inline void LinkedList<T>::push(const T& element)
{
    Node *new_node = new Node(element);
    if (head == nullptr)
    {
        head = tail = new_node;
        return;
    }
    
    tail -> next_= new_node;
    tail = new_node;
}

//pop
template <typename T>
inline void LinkedList<T>::pop()
{
    if(head == nullptr){
        return;
    }
    
    Node *new_node = head;
    while(new_node->next_->next_ != nullptr)
    {
        new_node = new_node->next_;
    }
    delete new_node->next_;
    new_node->next_ = nullptr;
}


//delete specific element
template<typename T>
inline void LinkedList<T>::popAt(const size_t& index)
{
    if (index >= size)
    {
        std::out_of_range("Out of range!!\n");
    }
    --size;
    
    if (index == 0)
    {
        Node* tempHead = head;
        head = tempHead->next_;
        delete tempHead;
        return;
    }
    
    Node* previousToNodeToRemove = head;
    
    for (size_t i = 0; i < index - 1; i++)
    {
        previousToNodeToRemove = previousToNodeToRemove->next_;
    }
    
    Node* nodeToRemove = previousToNodeToRemove->next_;
    previousToNodeToRemove->next_ = nodeToRemove->next_;
    delete nodeToRemove;
}

//insert after a given element
template <typename T>
inline void LinkedList<T>::insertAfter(const T& previous, const T& new_value)
{
    Node *new_node = new Node(new_value);
    if (previous == head->value_) {
        new_node->next_ = head->next_;
        head->next_ = new_node;
        return;
    }
    
    Node *temp = head;
    while (temp->value_ != previous) {
        temp = temp->next_;
        if (temp == nullptr) {
            return;
        }
    }
    new_node->next_ = temp->next_;
    temp->next_ = new_node;
}

//delete first element
template <typename T>
inline void LinkedList<T>::removeFist()
{
    if(head == nullptr){
        return;
    }
    
    Node *temp = head;
    head = head->next;
    delete temp;
}


//delete last element
template <typename T>
inline void LinkedList<T>::removeLast()
{
    if (head == nullptr) {
        return;
    }
    //check if next element is NULL
    if (head->next_ == nullptr) {
        delete head;
        return;
    }
    
    Node *temp = head;
    head = head->next_;
    delete temp;
    
    Node *previous_last = head;
    
    //find the previous to the last node(second last element)
    while(previous_last->next_->next_ != nullptr)
    {
        previous_last = previous_last->next_;
    }
    //delete last node
    delete (previous_last->next_);
    
    //make the previous_last element to be last
    previous_last->next_ = nullptr;
}

//search
template <typename T>
inline bool LinkedList<T>::search(const T& X)
{
    Node* current = head;
    while (current != nullptr) {
        if (current->value_ == X)
            return true;
        current = current->next_;
    }
    return false;
}

//find position Nth of the node 
template <typename T>
inline T LinkedList<T>::findNodeInLL(const T& X)
{
    int index = 0;
    Node *temp = head;
    
    while(temp!= nullptr){
        if(temp->value_ == X){
            //If element found return index
            return index;
        }
        temp = temp->next_;
        index++;
    }
    return -1;
}

//delete after a given iterator
template <typename T>
inline T LinkedList<T>::deleteAfter(Iterator iter)
{
    if (iter == nullptr || iter->next_ == nullptr) {
        return T();
    }
    
    Node *after = iter->next_;
    iter->next_ = after->next_;
    
    const T copyValue = after->value_;
    
    delete after;
    return copyValue;
    
}

//operator[]
template <typename T>
inline T LinkedList<T>::operator[](const size_t &index) const
{
    Node *curr = head;
    size_t counter = index;
    while (curr != nullptr && counter --> 0)
    {
        curr = curr->next_;
    }
    
    if(curr == nullptr)
    {
        return T();
    }
    else
    {
        return curr->value_;
    }
    
}

//operator +=
template <typename T>
inline LinkedList<T>& LinkedList<T>::operator+=(const T& other)
{
    push(other);
    return *this;
}

//operator ++
template <typename T>
inline LinkedList<T>& LinkedList<T>::operator++()
{
    Node *current = head;
    if (current == nullptr) {
        throw std::runtime_error("out of range for iterator");
    }
    current = current->next_;
    
    return *this;
}

//operator ==
template <typename T>
inline bool LinkedList<T>::operator==(const T& other) const
{
    return head == other.head;
}


//operator !=
template <typename T>
inline bool  LinkedList<T>::operator!=(const T& other) const
{
    return head != other.head;
}




//operator=
template <typename T>
inline LinkedList<T>& LinkedList<T>::operator=(const T& other)
{
    if(this != other)
    {
        clear();
        copy(other);
    }
    return *this;
}


//TODO
template <typename T>
inline T LinkedList<T>::operator*(const T &element)
{
}


//get sum of elements
template <typename T>
inline T LinkedList<T>::sumList()
{
    Node *current = head;
    int sum = 0;
    while(current!=nullptr)
    {
        sum += current->value_;
        current = current->next_;
    }
    return sum;
}

//шаблон с константен тип matrix20
template <typename T>
using matrix20 = T[20][20];


//TODO
template <typename T>
inline int LinkedList<T>::map1(const T &X) const
{
}

//Да се напише функция bool duplicates (...), която проверява дали в
//    контейнер има дублиращи се елементи.
template <typename T>
inline bool LinkedList<T>::duplicates()
{
    if (head == nullptr) {
        return false;
    }
    if(head->next_ == nullptr)
    {
        return false;
    }
    Node  *current = head;
    int counter = 0;
    while(current != nullptr)
    {
        if (current->value_ == current->next_->value_) {
            return true;
            counter++;
        }
        current = current->next_;
        if (current->next_ == nullptr) {
            return false;
        }
    }
    
    
    return counter == 2;
}

//Да се напише фунцкия bool issorted (...), която проверява дали елементите на даден контейнер са подредени в нарастващ или в намаляващ ред.
template <typename T>
inline bool LinkedList<T>::issorted()
{
    if (head == nullptr) {
        return true;
    }
    
    for (Node *temp = head; temp->next_ != nullptr; temp = temp->next_) {
        if (temp->value_ >= temp->next_->value_ && temp->value_ <= temp->next_->value_) {
            return false;
        }
    }
    return true;
}


//reverse the linked list;
template <typename T>
inline void LinkedList<T>::reverseList()
{
    Node *current = head;
    Node *previous = nullptr;
    Node *next1 = nullptr;
    while (current != nullptr) {
        next1 = current->next_;
        current->next_ = previous;
        previous = current;
        current = next1;
    }
    head = previous;
}

template <typename T>
inline LinkedList<T>& LinkedList<T>::swap(LinkedList& other)
{
    swap(head, other.head);
    swap(tail, other.tail);
    
    return *this;
}

//
//Да се напише фунцкия bool palindrom (...), която проверява дали
//редицата от елементите на даден контейнер обрзува палиндром (т.е. дали
//се чете еднакво както отляво надясно така и отдяно наляво).
//whether if it is a palindrome
template <typename T>
inline bool LinkedList<T>::palindrom()
{
    Node* temp = head;
    std::stack<int> stack1;
    while (temp != nullptr)
    {
        stack1.push(temp->value_);
        temp = temp->next_;
    }
    
    do {
        int i = stack1.top();
        stack1.pop();
        if (head->value_ != i)
        {
            return false;
        }
        head = head->next_;
    } while (head != nullptr);
    
    
    return true;
    
}


//clear list
template <typename T>
inline void LinkedList<T>::clear()
{
    Node *previous = head;
    while(head)
    {
        head = head->next_;
        delete previous;
        previous = head;
    }
}


//insert a node at the head of a linked list
template <typename T>
inline void LinkedList<T>::insertAtHead(int firs)
{
    Node*  new_node = new Node(firs);
    new_node->next_ = head;
    head = new_node;
}

//insert at tail
template <typename T>
inline void LinkedList<T>::insertAtTail(int last)
{
    Node *new_node = new Node(last);
    Node *temp = head;
    while (temp->next_ != nullptr) {
        temp = temp->next_;
    }
    temp->next_ = new_node;
}

//input list
template <typename T>
inline void LinkedList<T>::inputList()
{
    int new_node;
    std::cin >> new_node;
    
    while (new_node != -1)
    {
        if (head == nullptr)
        {
            insertAtHead(new_node);
        }
        else
        {
            insertAtTail(new_node);
        }
        std::cin >> new_node;
    }
}

//print list
template <typename T>
inline void LinkedList<T>::printList()
{
    Node* node = head;
    while (node != nullptr)
    {
        std::cout << " " << node -> value_;
        node = node -> next_;
    }
}


//ITERATOR ---------------------------------------------------
template <typename T>
inline LinkedList<T>::Iterator::Iterator(Node *ptr) : myPointer(ptr) {}

template <typename T>
inline typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++()
{
    *this++;
    return *this;
}

template <typename T>
inline bool LinkedList<T>::Iterator::operator==(const Iterator& other) const
{
    return myPointer == other.myPointer;
}

template <typename T>
inline bool LinkedList<T>::Iterator::operator!=(const Iterator& other) const
{
    return myPointer != other.myPointer;
}


template <typename T>
inline typename LinkedList<T>::Node* LinkedList<T>::Iterator::operator->()
{
    return myPointer;
}

template<typename T>
inline typename LinkedList<T>::Node& LinkedList<T>::Iterator::operator*()
{
    return myPointer;
}

template<typename T>
inline typename LinkedList<T>::Node& LinkedList<T>::Iterator::operator*() const
{
    return myPointer;
}

template<typename T>
inline typename LinkedList<T>::Node* LinkedList<T>::Iterator::getPointer() const noexcept
{
    return myPointer;
}

template<typename T>
inline typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
    return Iterator(head);
}

template<typename T>
inline typename LinkedList<T>::Iterator LinkedList<T>::end()
{
    return Iterator();
}
























