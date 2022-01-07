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

int random_select(int a[], int p, int r, int i)
{
    if (p == r)
        return a[p];
    int q = random_partition(a, p, r);
    int k = p - q + 1;
    if (k == i)
        return a[q];
    else if (i < k)
        return random_select(a, p, q - 1, i);
    else
        return random_select(a, q + 1, r, i - k);
}