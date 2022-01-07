#include "common.h"

int main()
{
    std::vector<int> A = {-10, -1, -100, 20};
    int sum = A[0];
    int ans = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        sum = std::max(sum + A[i], A[i]);
        ans = std::max(ans, sum);
    }
    std::cout << ans << '\n';
}