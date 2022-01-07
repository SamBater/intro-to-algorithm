#include "common.h"

void make_random_vector(std::vector<int> &v)
{
    int n = v.size();
    int last = n - 1;
    for (int i = 0; i < last; i++)
    {
        int index = i + rand() % (n - i);
        std::swap(v[i], v[index]);
    }
}

int main()
{
    std::vector<int> v = Create_Random_Vector();
    sort(v.begin(), v.end());
    make_random_vector(v);
    std::cout << v;
}