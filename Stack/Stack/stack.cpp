#include <iostream>
#include <stack>


void printStackElement(std::stack<int> stk)
{
    while (!stk.empty()) {
        std::cout << stk.top() << '\n';
        stk.pop();
    }
}

int main(){
    std::stack<int>stackElements;
    
    if (stackElements.empty() == true)
    {
        std::cout << "The stack is empty\n";
    }
    else
    {
        std::cout << "The stack is NOT empty\n";
    }
    
    for (int i = 1; i < 10; i++) {
        stackElements.push(i);
    }
    //Pops the topmost element, this case it is 9, as its the LAST IN, so it will be FIRST OUT
    stackElements.pop();
    printStackElement(stackElements);
    
    std::cout << "Stack size is: " << stackElements.size() << '\n';
    
    
    return 0;
}
