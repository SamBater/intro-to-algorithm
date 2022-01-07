#include "queue.hpp"
#include "stack.hpp"
#include <iostream>
#include <cassert>
int main()
{
    YYDS::stack<int> s;
    YYDS::queue<int> q;

    s.push(1);
    s.push(2);

    s.pop();
    assert(s.top() == 1);
    q.enqueue(102);
    q.enqueue(2);
    q.enqueue(3);
    assert(q.first() == 102);
    q.deque();
    q.deque();
    assert(q.size() == 1);
}