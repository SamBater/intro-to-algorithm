#include <iostream>
#include <algorithm>
#include <stdlib.h>
int partition(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;
    int j = p;

    //分成四个区域
    //if k <= i          a[k] < x
    //if i+1 <= k <= j-1 a[k] > x
    //if k == r          a[k] == x
    for (j = p; j < r; j++)
    {
        if (a[j] < x)
        {
            i++;
            std::swap(a[i], a[j]);
        }
    }

    std::swap(a[i + 1], a[r]);
    return i + 1;
}

int random_partition(int a[], int p, int r)
{
    int i = rand() % (r - p + 1) + p;
    std::swap(a[i], a[r]);
    return partition(a, p, r);
}

void quick_sort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = random_partition(a, p, r);
        quick_sort(a, p, q - 1);
        quick_sort(a, q + 1, r);
    }
}

int main()
{
    int ar[] = {2, 50, -132, 522, 13, 74, -456, 23};
    quick_sort(ar, 0, 7);
    for (int i = 0; i < 7; i++)
        std::cout << ar[i] << " ";
    std::cout << "\n";
}