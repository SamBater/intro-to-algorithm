#include "common.h"

std::vector<int> Create_Random_Vector(int size, int max)
{
    srand(time(0));
    std::vector<int> vec;
    for (int i = 0; i < size; i++)
        vec.push_back(rand() % max);
    return vec;
}

bool is_sorted(std::vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < v[i - 1])
            return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &out, std::vector<int> &v)
{
    for (const auto &x : v)
        out << x << ' ';
    out << '\n';
    return out;
}