#include <iostream>
#include "stack.h"
#include <cassert>

void get_top_of_stack()
{
    Stack<int> stk;
    for (int i = 1; i <= 12; i++)
    {
        stk.push(i);
    }
    
    stk.pop();
    std::cout << std::boolalpha << stk.isEmpty();
    std::cout << '\n';
    std::cout << stk.getSize();
    std::cout << '\n';
    std::cout << stk.top();
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    get_top_of_stack();
    return 0;
}
