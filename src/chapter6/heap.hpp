#include <algorithm> //std::swap
#include <vector>
class Heap
{

public:
    Heap(int a[], int heapSize)
    {
        for (int i = 0; i < heapSize; i++)
            arr.push_back(a[i]);
        this->heapSize = heapSize;
        build_max_heap(arr, heapSize);
    }

    //维持堆的性质 O(h) O(lgn)
    void max_heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < heapSize && arr[l] > arr[largest])
            largest = l;
        if (r < heapSize && arr[r] > arr[largest])
            largest = r;
        if (largest != i)
        {
            std::swap(arr[i], arr[largest]);
            max_heapify(largest);
        }
    }
    int heapSize;

protected:
    inline int
    parent(int i)
    {
        return i * 1.0 / 2 - 0.5f;
    }

    inline int left(int i)
    {
        return i * 2 + 1;
    }

    inline int right(int i)
    {
        return i * 2 + 2;
    }
    //建大堆 O(nlgn)  渐进准确：O(n)
    void build_max_heap(int a[], int heapSize)
    {
        for (int i = heapSize / 2; i >= 0; i--)
        {
            max_heapify(i);
        }
    }

    void build_max_heap(std::vector<int> a, int heapSize)
    {
        for (int i = heapSize / 2; i >= 0; i--)
        {
            max_heapify(i);
        }
    }
    std::vector<int> arr;
};
