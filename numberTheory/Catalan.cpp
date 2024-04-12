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
    return C(n % m, r % m, m) * Lucas(n / m, r / m, m) % m;
}
signed main()
{
    int n, mod;
    cin >> n >> mod;
    for (int i = 1; i <= 200; i++)
    {
        fac[i] = fac[i - 1] * i;
        // fac[i]%=mod;
    }
    printf("%lld\n", Lucas(n * 2, n, mod) / (n + 1)); // 取模除法会出问题
    return 0;
}