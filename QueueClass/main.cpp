#include <iostream>
#include "Queue.h"
#include <cassert>

void check_queue()
{
    Queue<int> que;
    que.push(3);
    que.push(221);
    que.push(12);
    que.push(34345);
    assert(que.getSize() == 4);
    assert(que.isEmpty() == false);
    assert(que.front() == 3);
    assert(que.back() == 34345);
}

int main()
{
    check_queue();
    return 0;
}
