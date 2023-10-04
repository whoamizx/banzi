#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    ll res = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res + a) % m;
        }
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}
int main()
{
    ll a = 0x7877665544332211;
    ll b = 0x7988776655443322;
    ll m = 0x998776655443322;
    cout << mul(a, b, m) << "\n";
    return 0;
}