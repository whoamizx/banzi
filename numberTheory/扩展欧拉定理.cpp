#include <bits/stdc++.h>
using namespace std;
#define int long long
// https://www.luogu.com.cn/problem/P5091
// 求a的b次方对m取模
// b特别大
int fastpow(int a, int n, int mod)
{
    a %= mod;
    int ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        n >>= 1;
    }
    return ans;
}
// 欧拉函数
int euler(int n)
{
    int ans = n;
    for (int p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            ans = (ans / p) * (p - 1);
            while (n % p == 0)
            {
                n /= p;
            }
        }
    }
    if (n != 1)
    {
        ans = ans / n * (n - 1);
    }
    return ans;
}
// 记录b是否大于等于euler(m)
int op;
// 快读取模
int read(int mod)
{
    op = 0;
    int x = 0;
    int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        if (x >= mod) // 大于则记录下来
        {
            op = 1;
        }
        x %= mod;
        ch = getchar();
    }
    return x * f;
}
signed main()
{
    int a, m, b;
    cin >> a >> m;
    int em = euler(m);
    b = read(em);
    // 根据扩展欧拉定理,如果大于就加上euler(m)
    if (op)
    {
        b += em;
    }
    //	printf("%lld %lld %lld %lld\n",a,b,m,em);
    printf("%lld\n", fastpow(a, b, m));
    return 0;
}
