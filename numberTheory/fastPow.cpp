#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fastpow(ll a, ll n, ll mod)
{
    ll ans = 1;
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
int main()
{
    ll a, b, p;
    cin >> a >> b >> p;
    printf("%lld^%lld mod %lld=%lld\n", a, b, p, fastpow(a, b, p));
    return 0;
}