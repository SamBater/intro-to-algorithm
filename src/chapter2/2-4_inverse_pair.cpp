//2-4

#include "common.h"

static int inverse_cnt = 0;

void merge(std::vector<int> &a, int p, int q, int r)
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
        {
            int distance = p + i - k;
            distance = distance < 0 ? -distance : distance;
            inverse_cnt += distance;
            a[k++] = L[i++];
        }
        else
        {
            int distance = q + j - k + 1;
            distance = distance < 0 ? -distance : distance;
            inverse_cnt += distance;
            a[k++] = R[j++];
        }
    }
    //不使用哨兵需要加上以下：
    while (i < n1)
    {
        int distance = p + i - k;
        distance = distance < 0 ? -distance : distance;
        inverse_cnt += distance;
        a[k++] = L[i++];
    }
    while (j < n2)
    {
        int distance = q + j - k + 1;
        distance = distance < 0 ? -distance : distance;
        inverse_cnt += distance;
        a[k++] = R[j++];
    }

    delete L, R;
}

void merge_sort(std::vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main()
{
    std::vector<int> v = {2, 3, 8, 6, 1};
    merge_sort(v, 0, v.size() - 1);
    std::cout << inverse_cnt / 2 << '\n';
}