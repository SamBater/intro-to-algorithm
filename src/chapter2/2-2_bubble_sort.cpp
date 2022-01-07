#include "common.h"

void bubble_sort(std::vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = a.size() - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
                std::swap(a[j], a[j - 1]);
        }
    }
}
int main()
{
    auto v = Create_Random_Vector();
    bubble_sort(v);
    std::cout << v;
}