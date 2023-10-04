#include <bits/stdc++.h>
using namespace std;
// 你可以对这个序列进行操作，每次操作可以选择一个元素，把它加1，经过不
// 超过k次操作之后，希望序列里面的最小值最大。问这个值是多少
const int N = 1e5 + 10;
int n;
int a[N];
long long k;
long long calc(long long k)
{
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += max(0LL, k - a[i]); // 0LL是long long 0
    }
    return res;
}
int main()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    long long L = 1, R = 1e14;
    while (L + 1 < R)
    {
        long long M = (L + R) / 2;
        if (calc(M) <= k)
        {
            L = M;
        }
        else
        {
            R = M;
        }
    }
    printf("%lld\n", L);
    return 0;
}