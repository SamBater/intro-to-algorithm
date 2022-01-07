#include <iostream>
#include <vector>
#include <cstdlib>
int randomSize = 10;

void inserted_sort(std::vector<int> &a)
{
    int length = a.size();
    for (int i = 1; i < length; i++)
    {
        int key = a[i];
        int j = i - 1;
        for (j = i - 1; j >= 0 && key < a[j]; j--)
            a[j + 1] = a[j];
        a[j + 1] = key;
    }
}

int main()
{
    std::vector<int> arr;
    for (int i = 0; i < randomSize; i++)
        arr.push_back(rand() % randomSize);

    inserted_sort(arr);

    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
}