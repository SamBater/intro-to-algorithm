#include "common.h"

void insert(std::vector<int> &v, int j, int key)
{
    int i;
    for (i = j; i >= 0 && v[i] > key; i--)
        v[i + 1] = v[i];
    v[i + 1] = key;
}

void inserted_sort(std::vector<int> &v, int n)
{
    if (n > 0)
    {
        inserted_sort(v, n - 1);
        insert(v, n - 1, v[n]);
    }
}
/*
T(n)= T(n-1) + O(n)
    = 1+2+..+n-1+n
    = Sum(1,n)
    = (n(n+1)) / 2
    = n^2
*/

int main()
{
    auto v = Create_Random_Vector();
    inserted_sort(v, v.size() - 1);
    std::cout << v;
}
