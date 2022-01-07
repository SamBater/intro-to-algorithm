#include <bits/stdc++.h>
using namespace std;

void bucket_sort(vector<int> &nums)
{
    vector<vector<int>> bucket(10);
    for (int i = 0; i < nums.size(); i++)
    {
        int index = nums[i] / 10;
        bucket[index].push_back(nums[i]);
    }

    for (int i = 0; i < bucket.size(); i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }

    int j = 0, k = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        while (k == bucket[j].size())
        {
            j++;
            k = 0;
        }
        nums[i] = bucket[j][k];
        k++;
    }

    for (auto &n : nums)
    {
        cout << n << " ";
    }
}

int main()
{
    vector<int> arr = {23, 42, 17, 9, 6, 63, 72, 33, 63, 28, 43};
    bucket_sort(arr);
}