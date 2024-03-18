#include <bits/stdc++.h>
using namespace std;
#define int long long
// 能mod的地方就多mod几次
int fastpow(int a, int n, int mod)
{
    int ans = 1;
    // 先mod防止爆
    a %= mod;
    while (n)
    {
        if (n & 1)
        {
            ans = (ans * a) % mod;
        }
        // 放到外面,因为每次右移都要加倍
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}
signed main()
{
    int a, b, p;
    cin >> a >> b >> p;
    printf("%lld^%lld mod %lld=%lld\n", a, b, p, fastpow(a, b, p));
    return 0;
}