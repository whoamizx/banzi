// 对于给定的一段正整数序列，逆序对就是序列中ai>aj;且i<j的有序对
// 求逆序对数目,可能有重复数字。
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
int c[N];
int cnt=0;
void mergesort(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int m = (l + r) / 2;
    int p1 = l, p2 = m + 1,tot = 0;
    mergesort(l, m);
    mergesort(m + 1, r);
    while (p1 <= m && p2 <= r)
    {
        // 小于等于时更新答案,如果有重复元素
        if (a[p1] <= a[p2])
        {
            c[++tot] = a[p1++];
            cnt+=p2-m-1;
        }
        else
        {
            c[++tot] = a[p2++];
        }
    }
    while (p1 <= m)
    {
        c[++tot] = a[p1++];
        cnt+=p2-m-1;
    }
    while (p2 <= r)
    {
        c[++tot] = a[p2++];
    }
    for (int i = l; i <= r; i++)
    {
        a[i] = c[i - l + 1];
    }
}
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    mergesort(1, n);
    printf("%lld\n",cnt);
    return 0;
}