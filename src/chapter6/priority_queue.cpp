#include <iostream>
#include "priority_queue.hpp"
int main()
{
    int arr[] = {3, 64, 21, 0, 25, 52, 220, -5};
    priority_queue q(arr, 8);
    q.increase_key(1, 128);
    q.increase_key(1, 566);
    q.increase_key(0, 1024);
    q.insert(2048);
    for (int i = 0; i < 9; i++)
    {
        std::cout << q.extract_max() << " ";
    }
}