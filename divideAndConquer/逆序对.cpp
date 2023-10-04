#include <bits/stdc++.h>
using namespace std;
// 对于给定的一段正整数序列，逆序对就是序列中ai>aj;且i<j的有序对
// 求逆序对数目,可能有重复数字。
const int N = 5e5 + 10;
int n, a[N], c[N];
long long solve(int l, int r)
{
    if (l == r)
    {
        return 0;
    }
    int m = (l + r) / 2;
    long long res = solve(l, m) + solve(m + 1, r);
    int p1 = l, p2 = m + 1, cnt = 0;
    while (p1 <= m && p2 <= r)
    {
        // 小于等于时更新答案,如果有重复元素
        if (a[p1] <= a[p2])
        {
            c[++cnt] = a[p1++];
            res += p2 - m - 1;
        }
        else
        {
            c[++cnt] = a[p2++];
        }
    }
    while (p1 <= m)
    {
        c[++cnt] = a[p1++];
        res += p2 - m - 1;
    }
    while (p2 <= r)
    {
        c[++cnt] = a[p2++];
    }
    for (int i = l; i <= r; i++)
    {
        a[i] = c[i - l + 1];
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%lld\n", solve(1, n));
    return 0;
}