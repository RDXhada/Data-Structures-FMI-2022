#include <iostream>

//DLL

//Constructor
template <typename T>
inline DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}


//copy constructor
//copy
template <typename T>
inline void DoublyLinkedList<T>::copy(const DoublyLinkedList<T> &other)
{
    if (other.head == nullptr)
    {
        return;
    }
    Node *otherNode = other.head;
    head = new Node(otherNode->value);
    
    Node *current = head;
    while (otherNode->next)
    {
        otherNode = otherNode->next;
        current->next = new Node(otherNode->value, current);
        current = current->next;
    }
    tail = current;
}
template <typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &other) { copy(other); }


//destructor
template <typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}

template <typename T>
inline void DoublyLinkedList<T>::clear()
{
    while (head!=nullptr) {
        Node *current = head;
        head = head->next;
        delete current;
    }
}

template <typename T>
inline  const size_t DoublyLinkedList<T>::getSize() const
{
    Node *current = head;
    size_t counter = 0;
    while (current!=nullptr)
    {
        counter++;
        current = current->next;
    }
    return counter;
}

template <typename T>
inline DoublyLinkedList<T>& DoublyLinkedList<T>::pushFirst(const T &element)
{
    Node *new_node = new Node(element, nullptr, head);
    if (head == nullptr)
    {
        tail = new_node;
    }
    else
    {
        head->prev = new_node;
    }
    head = new_node;
    return *this;
}


template <typename T>
inline DoublyLinkedList<T>& DoublyLinkedList<T>::pushLast(const T &element)
{
    if (head == nullptr)
    {
        pushFirst(element);
        return *this;
    }
    Node *new_node = new Node(element, tail);
    tail->next = new_node;
    tail = new_node;
    return *this;
}

template <typename T>
inline DoublyLinkedList<T>& DoublyLinkedList<T>::popFirst()
{
    if (head == nullptr)
    {
        throw std::runtime_error("Cant delete from empty list.");
    }
    Node *temp = head;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    delete temp;
    return *this;
    
}

template <typename T>
inline DoublyLinkedList<T>& DoublyLinkedList<T>::popLast()
{
    if (head == nullptr)
    {
        throw std::runtime_error("error");
    }
    if (head->next == nullptr)
    {
        delete head;
        head = tail = nullptr;
        return *this;
    }
    Node *previous = tail->prev;
    previous->next = nullptr;
    delete tail;
    tail = previous;
    return *this;
}

template <typename T>
inline void DoublyLinkedList<T>::update(const size_t& position, const T& element)
{
    Node *current = head;
    for (size_t  i = 0; i < position; i++) {
        current = current->next;
    }
    current->value = element;
}

template <typename T>
inline void DoublyLinkedList<T>::reverse()
{
    Node *temp = nullptr;
    Node *current = head;
    while (current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr)
    {
        head = temp->prev;
    }
}

template <typename T>
inline void DoublyLinkedList<T>::sort()
{
    int swap;
    Node *ptr1;
    Node *ptr2 = nullptr;
    if (head == nullptr)
    {
        throw std::runtime_error("Cannot sort empty list.");
    }
    do {
        swap = 0;
        ptr1 = head;
        while (ptr1->next != ptr2)
        {
            if (ptr1 ->value > ptr1->next->value)
            {
                std::swap(ptr1->value, ptr1->next->value);
                swap = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while(swap);
}

template <typename T>
inline DoublyLinkedList<T>& DoublyLinkedList<T>::removeElement(int position)
{
    Node *current = head;
    Node *previous = nullptr;
    if (position == 1)
    {
        popFirst();
        return *this;
    }
    while (position > 1)
    {
        current = current->next;
        position--;
    }
    if (current->next == nullptr)
    {
        popLast();
    }
    else
    {
        previous = current->prev;
        previous->next = current->next;
        current->next->prev = previous;
        delete current;
        current = nullptr;
        
    }
    return *this;
}

template<typename T>
inline std::vector<T> DoublyLinkedList<T>::toVector()
{
    Node* current = head;
    std::vector<T> v;
    
    while (current != nullptr)
    {
        v.push_back(current->value);
        current = current->next;
    }

    return v;
}


template <typename T>
inline void DoublyLinkedList<T>::print()
{
    Node *current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
}



//Iterator-----------------------------------------------------------------------------------
template <typename T>
inline typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator++()
{
    myPointer= myPointer->next;
    return *this;
}

template <typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator++(int)
{
    Iterator temp(*this);
    operator++();
    return temp;
}

template <typename T>
inline typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator--()
{
    myPointer = myPointer->prev;
    return *this;
}

template <typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator--(int)
{
    Iterator temp(*this);
    operator--();
    return temp;
}


template <typename T>
inline bool DoublyLinkedList<T>::Iterator::operator==(const Iterator &rhs) const
{
    return myPointer == rhs.myPointer;
}

template <typename T>
inline bool DoublyLinkedList<T>::Iterator::operator!=(const Iterator &rhs) const
{
    return myPointer != rhs.myPointer;
}

template <typename T>
inline T& DoublyLinkedList<T>::Iterator::operator*()
{
    return myPointer->value;
}

template <typename T>
inline T* DoublyLinkedList<T>::Iterator::operator->()
{
    return myPointer->value;
}













