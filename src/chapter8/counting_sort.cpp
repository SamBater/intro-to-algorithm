#include <iostream>
#include <vector>
#include <cstdlib>

void counting_sort(std::vector<int> inputArr)
{
    std::vector<int> tmpArr(inputArr.size());
    for (int i = 0; i < inputArr.size(); i++)
    {
        tmpArr[inputArr[i]]++;
    }

    for (int i = 1; i < inputArr.size(); i++)
    {
        tmpArr[i] += tmpArr[i - 1];
    }

    std::vector<int> sortedArr(inputArr.size());
    for (int i = inputArr.size() - 1; i >= 0; i--)
    {
        sortedArr[tmpArr[inputArr[i]]--] = inputArr[i];
    }

    for (auto &i : sortedArr)
    {
        std::cout << i << " ";
    }
}

// int main()
// {
//     std::vector<int> arr(500);
//     srand(time(0));
//     for (int i = 0; i < 500; i++)
//     {
//         arr[i] = rand() % 500;
//     }
//     counting_sort(arr);
// }