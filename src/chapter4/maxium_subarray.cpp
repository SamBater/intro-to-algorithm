#include <iostream>
#include <tuple>
using namespace std;
tuple<int, int, int> max_crossing_subarray(int a[], int l, int r)
{
    int mid = (l + r) / 2;
    int leftSum = 0, rightSum = 0, sum = 0, leftStart = mid, rightStart = mid + 1;
    for (int i = mid; i >= l; i--)
    {
        sum += a[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            leftStart = i;
        }
    }

    sum = 0;
    for (int j = mid + 1; j <= r; j++)
    {
        sum += a[j];
        if (sum > rightSum)
        {
            rightSum = sum;
            rightStart = j;
        }
    }
    return make_tuple(leftStart, rightStart, leftSum + rightSum);
}

tuple<int, int, int> max_subarray(int a[], int l, int r)
{
    auto ans = make_tuple(l, r, a[l]);
    if (l == r)
        return ans;
    else
    {
        int mid = (l + r) / 2;
        tuple<int, int, int> la = max_subarray(a, l, mid);
        tuple<int, int, int> ra = max_subarray(a, mid + 1, r);
        tuple<int, int, int> ma = max_crossing_subarray(a, l, r);

        if (get<2>(la) > get<2>(ra) && get<2>(la) > get<2>(ma))
            return la;
        if (get<2>(ra) > get<2>(la) && get<2>(ra) > get<2>(ma))
            return ra;
        if (get<2>(ma) > get<2>(la) && get<2>(ma) > get<2>(ra))
            return ma;
    }
}

int main()
{
    int arr[] = {-2, 8, -1, -2, 5, -3, 9, -5, 0};
    tuple<int, int, int> ans = max_subarray(arr, 0, 8);
    std::cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans);
}