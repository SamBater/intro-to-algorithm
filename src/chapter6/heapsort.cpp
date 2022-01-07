#include <iostream>
#include "heap.hpp"
#include <cstdlib>
// O(nlgn)
void heapsort(int a[], int size)
{
    Heap h(a, size);
    for (int i = size; i >= 1; i--)
    {
        std::swap(a[0], a[i]);
        h.heapSize--;
        h.max_heapify(0);
    }
    for (int i = 0; i < size; i++)
        std::cout << a[i] << " ";
}
const int randomSize = 100;
int main()
{
    int *arr = new int[randomSize];
    for (int i = 0; i < randomSize; i++)
        arr[i] = rand() % randomSize;
    heapsort(arr, randomSize);
}