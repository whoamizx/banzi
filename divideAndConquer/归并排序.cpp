#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int c[N];
void mergesort(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int m = (l + r) / 2;
    // int p1 = l, p2 = m + 1,tot = 0;
    mergesort(l, m);
    mergesort(m + 1, r);
    inplace_merge(a + l, a + m, a + r);
    // while (p1 <= m && p2 <= r)
    // {
    //     if (a[p1] < a[p2])
    //     {
    //         c[++tot] = a[p1++];
    //     }
    //     else
    //     {
    //         c[++tot] = a[p2++];
    //     }
    // }
    // while (p1 <= m)
    // {
    //     c[++tot] = a[p1++];
    // }
    // while (p2 <= r)
    // {
    //     c[++tot] = a[p2++];
    // }
    // for (int i = l; i <= r; i++)
    // {
    //     a[i] = c[i - l + 1];
    // }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(1, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}