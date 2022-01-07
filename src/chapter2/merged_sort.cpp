#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
int randomSize = 100;

void merge(int a[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1], *R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[p + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[q + i + 1];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    //不使用哨兵需要加上以下：
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];

    delete L, R;
}

void merged_sort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merged_sort(a, p, q);
        merged_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

int main()
{
    int *arr = new int[randomSize];
    for (int i = 0; i < randomSize; i++)
        arr[i] = rand() % 1000;

    merged_sort(arr, 0, randomSize - 1);

    for (int i = 0; i < randomSize; i++)
        std::cout << arr[i] << " ";
}