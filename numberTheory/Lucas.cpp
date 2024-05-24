#include <bits/stdc++.h>
using namespace std;
// 1<=n,m,p<=1e5
// https://www.luogu.com.cn/problem/P3807
#define int long long
const int N = 1e6 + 10;
int fac[N];
int fastPow(int a, int n, int m)
{
    int ans = 1;
    a %= m;
    while (n)
    {
        if (n & 1)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        n >>= 1;
    }
    return ans;
}
int inverse(int a, int m)
{
    // 返回阶乘的次方
    return fastPow(fac[a], m - 2, m);
}
int C(int n, int r, int m)
{
    // r>n,寄
    if (r > n)
    {
        return 0;
    }
    // 三个乘,两两模一下
    return ((fac[n] * inverse(r, m)) % m * inverse(n - r, m) % m);
}
int Lucas(int n, int r, int m)
{
    // r==0返回1
    if (r == 0)
    {
        return 1;
    }
    // 递归
    return (C(n % m, r % m, m) * Lucas(n / m, r / m, m)) % m;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, p;
        fac[0] = 1;
        scanf("%lld%lld%lld", &n, &m, &p);
        // 预处理阶乘
        // 放里面,因为要模p
        for (int i = 1; i <= (n + m); i++)
        {
            fac[i] = fac[i - 1] * i;
            fac[i] %= p;
        }
        printf("%lld\n", Lucas(n + m, n, p));
    }
    return 0;
}