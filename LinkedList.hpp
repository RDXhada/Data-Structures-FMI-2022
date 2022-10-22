//
//  LinkedList.hpp
//  secondWeek
//
//  Created by Dzhem Shenolov on 15.10.22.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp
#include <iostream>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T value_;
        Node *next_;
        
        Node(const T& value, Node* next = nullptr);
    };
    
    Node *head;
    Node *tail;
    size_t size;
    //copy constructor
    void copy(const LinkedList &other);
    void delete_();
    
public:
    //constructor
    LinkedList();
    LinkedList(const LinkedList &other);
    //destructor
    ~LinkedList();
    
    //size
    const size_t getSize() const;
    //Да се реализира метод int LList::count(int x), който преброява колко пъти елементът x се среща в списъка.
    size_t count(const T& element) const;
    //Да се реализира метод LList::push_back за добавяне на елемент от тип T към края на списъка.
    void push(const T& element);
    //pop
    void pop();
    //Да се реализира конструктор с два аргумента x и y от тип int. Конструкторът създава списък с елементи x, x + 1, ..., y, при положение, че x ≤ y.
    void updateAt(const size_t& index, const T& elem);
    
    //Да се реализира метод l1.append(l2), която добавя към края на списъка l1 всички елементи на списъка l2.
    void append(const LinkedList& other);
    
    //delete specific element in the list
    void popAt(const size_t& index);
    
    //operators
    T operator[](const size_t& index) const;
    LinkedList<T>& operator+=(const T& other);
    LinkedList<T>& operator=(const T& other);
    //TODO
    bool operator==(const T& other) const;
    //TODO
    bool operator!=(const T& other) const;
    //TODO
    T operator*(const T& element);
    
    
    T sumList();
    //Да се дефинира функция map, която прилага едноаргументна функция
    //    f : int → int към всеки от елементите на произволен контейнер с числа
    //    (int). Да се дефнира и шаблон на функцията за контейнер с произолен
    //    тип на елементите.
    int map1(const T& X) const;
    
//    Да се напише функция bool duplicates (...), която проверява дали в
//    контейнер има дублиращи се елементи.
    bool duplicates();
//    Да се напише фунцкия bool issorted (...), която проверява дали елементите на даден контейнер са подредени в нарастващ или в намаляващ ред.
    bool issorted ();
//    Да се напише фунцкия bool palindrom (...), която проверява дали
//    редицата от елементите на даден контейнер обрзува палиндром (т.е. дали
//    се чете еднакво както отляво надясно така и отдяно наляво).
    void reverseList();
    //TOOD
    bool palindrom();
    
    //insrt,remove,delete
    void insertAfter(const T& previous, const T& new_value);
    void removeFist(); //popFirst
    void removeLast(); //popLast
    T deleteAfter(Node *iterator);
    
    //search if the node is in the LinkedList
    bool search(const T& X);
    
    //find position
    T findNodeInLL(const T& X);
    
    //clear the list
    void clear();
    
    //print the list
    void printList();
    
    
};

#include "inlineList.inl"
#endif /* LinkedList_hpp */
