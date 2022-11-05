#include <iostream>
#include <cassert>
#include "LinkedList.h"

void check_reverse_LinkedList()
{
    LinkedList<int> list{ 1,2,3,4,5 };

        list.reverse();

        size_t expectedVal = 5;
        for (typename LinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it, --expectedVal)
            assert(*it == expectedVal);

        list.reverse();

        ++expectedVal;
        for (typename LinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it, ++expectedVal)
            assert(*it == expectedVal);
}

void check_sortLinekdList()
{
    LinkedList<int> list{12,3,45,6,7,8,9};
    list.sort();
    assert(std::vector<int>({3,6,7,8,9,12,45}) == list.to_vector());
}

void search_LL()
{
    LinkedList<int> list{2,67,45,5,6};
    std::cout<<list.search(67);
}


int main()
{
    check_reverse_LinkedList();
    check_sortLinekdList();
    search_LL();
    return 0;
}
