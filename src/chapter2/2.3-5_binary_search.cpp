#include "common.h"

int binary_search(std::vector<int> &v, int key)
{
    int l = 0, r = v.size() - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] == key)
            return mid;
        else if (v[mid] > key)
            r = mid - 1;
        else if (v[mid] < key)
            l = mid + 1;
    }
    return -1;
}

//recursive version
int binary_search(std::vector<int> &v, int l, int r, int key)
{
    if (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (key == v[mid])
            return mid;
        if (key < v[mid])
            return binary_search(v, l, mid - 1, key);
        if (key > v[mid])
            return binary_search(v, mid + 1, r, key);
    }
    return -1;
}

int main()
{
    std::vector<int> v = {234, 53, 34, 71, 235, 455, 344, 384, 500, 426, 443, 2244, 6040, 2367, 3221};
    sort(v.begin(), v.end());
    std::cout << "Mybs: " << binary_search(v, 0, v.size() - 1, 455) << '\n';

    auto it = std::find(v.begin(), v.end(), 455);
    int index = it - v.begin();

    std::cout << "std::find : " << index;
    std::cout << '\n';
}