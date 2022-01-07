#include "heap.hpp"
class priority_queue : public Heap
{
public:
    priority_queue(int a[], int heapSize) : Heap(a, heapSize)
    {
    }
    // O(lgn)
    void insert(int x)
    {
        arr.push_back(x);
        heapSize++;
        increase_key(heapSize - 1, x);
    }

    int maximum()
    {
        return arr[0];
    }

    // O(lgn)
    int extract_max()
    {
        int max = arr[0];
        arr[0] = arr[heapSize - 1];
        arr.erase(arr.end() - 1);
        heapSize--;
        max_heapify(0);
        return max;
    }

    void increase_key(int i, int key)
    {
        if (arr[i] > key)
            return; //
        arr[i] = key;
        while (i > 0 && arr[parent(i)] < key)
        {
            std::swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
};