#include <bits/stdc++.h>
using namespace std;
#define int long long
int fastpow(int a, int n, int mod)
{
    int ans = 1;
    a %= mod;
    while (n)
    {
        if (n & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}
// 求比这个数字小的正整数有几个与他互素
int eular(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {

            n /= i;
            ans = ans / i * (i - 1);
            while (n % i == 0)
        }
    }
    if (n > 1)
        ans = ans / n * (n - 1);
    return ans;
}
signed main()
{
    int a, p;
    scanf("%lld%lld", &a, &p);
    // 若p为素数,a的逆元为
    printf("%lld\n", fastpow(a, p - 2, p));
    // 若p不是素数,a的逆元
    printf("%lld\n", fastpow(a, eular(p) - 1, p));
    return 0;
}