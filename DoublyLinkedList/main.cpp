#include <iostream>
#include "DoublyLinkedList.h"
#include <vector>
#include <cassert>

void test_getSize_of_the_DLL()
{
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 12; i++) {
        list.pushLast(i);
    }
    assert(list.getSize() == 12);
    
    list.popLast();
    assert(list.getSize() == 11);
    list.reverse();
    list.removeElement(2);
    assert(list.getSize() == 10);
}

void push_First_element_DLL()
{
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 6; i++) {
        list.pushFirst(i);
    }
    assert(std::vector<int>({6,5,4,3,2,1}) == list.toVector());
    
    list.popFirst();
    list.reverse();
    list.popFirst();
    assert(std::vector<int>({2,3,4,5}) == list.toVector());
}

void push_Last_Element_DLL()
{
    DoublyLinkedList<int> list;
    for (int j = 1; j < 7; j++) {
        list.pushLast(j);
    }
    assert(std::vector<int>({1,2,3,4,5,6}) == list.toVector());
    list.reverse();
    assert(std::vector<int>({6,5,4,3,2,1}) == list.toVector());
    list.popFirst();
    assert(std::vector<int>({5,4,3,2,1}) == list.toVector());

}

void pop_First_Element_DLL()
{
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 13; i++) {
        list.pushLast(i);
    }
    for (int j = 1; j <= 5; j++) {
        list.popFirst();
    }
    assert(std::vector<int>({6,7,8,9,10,11,12,13}) == list.toVector());
}

void pop_Last_Element_DLL()
{
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 10; i++) {
        list.pushFirst(i);
    }
    for (int j = 1; j <= 4; j++) {
        list.popLast();
    }
    assert(std::vector<int>({10,9,8,7,6,5}) == list.toVector());
}

void remove_Element_DLL()
{
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 8; i++) {
        list.pushLast(i);
    }
    list.removeElement(3);
    assert(std::vector<int>({1,2,4,5,6,7,8}) == list.toVector());
}

void copy_other_DLL()
{
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 3; i++) {
        list.pushLast(i);
    }
    DoublyLinkedList<int> list2(list);
    assert(std::vector<int>({1,2,3}) == list2.toVector());
    
    
}

void reverse_DLL()
{
    DoublyLinkedList<int> list;
    list.pushLast(13);
    list.pushFirst(1);
    list.pushLast(25);
    list.reverse();
    assert(std::vector<int>({25,13,1}) == list.toVector());
}

void is_it_sorted_DLL()
{
    DoublyLinkedList<int> list;
    list.pushLast(78);
    list.pushLast(3);
    list.pushLast(2);
    list.pushLast(36);
    list.sort();
    assert(std::vector<int>({2,3,36,78}) == list.toVector());
}

void check_clear_DLL()
{
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 36; i++) {
        list.pushLast(i);
    }
    list.clear();
    assert(list.getSize() == 0);
    assert(std::vector<int>({}) == list.toVector());
}


int main(){
    test_getSize_of_the_DLL();
    push_First_element_DLL();
    push_Last_Element_DLL();
    pop_First_Element_DLL();
    pop_Last_Element_DLL();
    remove_Element_DLL();
    copy_other_DLL();
    reverse_DLL();
    is_it_sorted_DLL();
    return 0;
}
