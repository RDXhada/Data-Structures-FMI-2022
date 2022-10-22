#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <iostream>
#include "LinkedList.hpp"

#include <vector>

TEST_CASE("Testing count method")
{
    LinkedList<int> list;
    for (int i = 0; i < 10; i++)
    {
        list.push(i);
    }
    CHECK(list.count(2) == 1);
    CHECK(list.count(0) == 1);
    CHECK(list.count(42123) == 0);

    list.push(2);
    CHECK(list.count(2) == 2);
}


TEST_CASE("Testing append")
{
    LinkedList<int> list;
    list.push(0);
    list.push(1);

    LinkedList<int> list2;
    list2.push(2);
    list2.push(3);

    list.append(list2);

    CHECK(list.getSize() == 4);

    for (size_t i = 0, count = 0; i <= 3; i++, count++)
        CHECK(list[count] == i);
}

TEST_CASE("Testing size of list")
{
    LinkedList<int> list;
    LinkedList<int> list2;
    for (int i = 0; i < 25; i++)
    {
        list.push(i);
    }
    CHECK(list.getSize() == 25);
    
    list2.push(3);
    list2.push(18);
    list2.push(215);
    list2.push(3123);
    CHECK(list2.getSize() == 4);
    list2.clear();
    CHECK(list2.getSize() == 0);
    
}

TEST_CASE("find position of node")
{
    LinkedList<int> list;
    list.push(1);
    list.push(12);
    list.push(234);
    list.push(13);
    CHECK(list.findNodeInLL(12) == 1);
}

TEST_CASE("search if we have such element")
{
    LinkedList<int> list;
    list.push(34);
    list.push(23);
    list.push(69);
    list.push(58);
    CHECK(list.search(34) == true);
    CHECK(list.search(13) == false);
}

TEST_CASE("Find if theres duplicates")
{
    LinkedList<int> list;
    list.push(1);
    list.push(2);
    list.push(2);
    list.push(3);
    CHECK(list.duplicates() == true);
}

TEST_CASE("Sum of the elements")
{
    LinkedList<int> list;
    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);
    CHECK(list.sumList() == 100);
}

TEST_CASE("whether the list is sorted ascending/descending")
{
    LinkedList<int> list;
    list.push(3);
    list.push(6);
    list.push(8);
    list.push(12);
    CHECK(list.issorted() == true);
}

TEST_CASE("whether the list is a palindrome")
{
    LinkedList<char> list;
    list.push('a');
    list.push('b');
    list.push('b');
    list.push('a');
    CHECK(list.palindrom() == true);
    
    LinkedList<int> list2;
    list2.push(12);
    list2.push(6);
    list2.push(6);
    list2.push(21);
    CHECK(list2.palindrom() == false);
}


int main()
{
    doctest::Context().run();
    LinkedList <int> LL1;
    LL1.push(3);
    LL1.push(5);
    std::cout << "List 1: ";
    LL1.printList();
    std::cout << '\n';
    LinkedList<int> LL2;
    LL2.push(66);
    LL2.push(89);
    std::cout << "List 2: ";
    LL2.printList();
    std::cout << '\n';
    std::cout << "After append we get: ";
    LL1.append(LL2);
    LL1.printList();
    std::cout << '\n';
    std::cout << "Remove last element: ";
    LL1.removeLast();
    LL1.printList();
    std::cout << '\n';
    std::cout << "Pop specific element";
    LL1.popAt(0);
    LL1.printList();
    std::cout << '\n';
//    std::cout << "Delete after: ";
//    LL1.deleteAfter();
    
    std::cout << '\n';
    std::cout << "List number 3: ";
    LinkedList<int> LL3;
    LL3.push(12);
    LL3.push(3);
    LL3.push(44);
    LL3.push(73);
    LL3.printList();
    std::cout << '\n';
    std::cout << "Cleared lists: ";
    LL3.clear();
    LL3.printList();
    
    //clear all lists data
    LL1.clear();
    LL2.clear();
    LL3.clear();
    
    std::cout << '\n';
    
//    std::cout << '\n';
//
//    std::vector<int> vec({1,2,3,4,5,6});
//
//    for(auto it = vec.begin(); it != vec.end(); ++it)
//    {
//        std::cout << *it << " ";
//    }
    return 0;
}



