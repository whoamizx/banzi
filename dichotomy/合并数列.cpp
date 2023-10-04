#include <bits/stdc++.h>
using namespace std;
// 有n个线性序列，第i个序列可以表示成k*x＋b;的形式(x = 0,1,2,.
//  将这些序列的数从小到大合并起来，前m个数的和是多少（重复出现的数合并后也会多次出现)
//  输入第一行一个数n
//  接下来n行每行两个数表示k, b最后一行一个数m
int n, k[1010], m;
int b[100010];
long long calc(int x)
{
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x >= b[i])
        {
            res += (x - b[i]) / k[i] + 1;
        }
    }
    return res;
}
// 等差数列公式
long long sum(int x)
{
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x >= b[i])
        {
            int y = (x - b[i]) / k[i] + 1;
            res += 1LL * (b[i] + (y - 1) * k[i] + b[i]) * y / 2;
        }
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &k[i], &b[i]);
    }
    scanf("%d", &m);
    int L = 0, R = 1e9;
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        if (calc(M) <= m)
        {
            L = M;
        }
        else
        {
            R = M;
        }
    }
    printf("%lld\n", sum(L) + 1LL * (m - calc(L)) * (L + 1));
    return 0;
}