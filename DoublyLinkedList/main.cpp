//
//  main.cpp
//  week3and4
//
//  Created by Dzhem Shenolov on 23.10.22.
//

#include <iostream>
#include "DLL.hpp"
#include <cassert>
#include <iterator>

void test_insertAfter_DDL()
{
    std::cout << "Test insertAfter:\n";
    DoublyLinkedList<int> list;
    list.insertAfter(nullptr, 10);
    assert (std::vector<int>({}) == list.toVector());
}

void test_NthPostiion()
{
    std::cout << "Test Nth position: \n";
    DoublyLinkedList<int> list;
    list.insertLast(12);
    list.insertLast(13);
    list.insertLast(23);
    list.insertLast(56);
    assert (list.GetNth(2) == 23);
}


int main() {
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 10; i++)
    {
        list.insertLast(i);
    }

    list.deleteFirst();
    list.deleteLast();
    std::cout << '\n';
    list.print();
    
    std::cout << '\n';
    
    test_insertAfter_DDL();
    test_NthPostiion();

        
    return 0;
}
