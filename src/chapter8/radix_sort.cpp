#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

void radix_sort(std::vector<int> &inputArr)
{
    int radix = 1;
    int maxBit = 1;
    std::vector<int> sortedArr(inputArr.size());

    int max = *(std::max_element(inputArr.begin(), inputArr.end()));
    max /= 10;
    while (max)
    {
        maxBit++;
        max /= 10;
    }

    for (int i = 0; i < maxBit; i++)
    {
        std::vector<int> count(10);
        for (int j = 0; j < inputArr.size(); j++)
        {
            int key = (inputArr[j] / radix) % 10;
            count[key]++;
        }

        for (int j = 1; j < 10; j++)
        {
            count[j] += count[j - 1];
        }

        for (int j = inputArr.size() - 1; j >= 0; j--)
        {
            int key = (inputArr[j] / radix) % 10;
            sortedArr[--count[key]] = inputArr[j];
        }
        radix *= 10;

        for (int i = 0; i < sortedArr.size(); i++)
        {
            inputArr[i] = sortedArr[i];
        }
    }

    for (auto &v : sortedArr)
    {
        std::cout << v << " ";
    }
}

int main()
{
    std::vector<int> vec{123, 5125, 26, 12, 6, 52, 323, 1, 14};
    radix_sort(vec);
}