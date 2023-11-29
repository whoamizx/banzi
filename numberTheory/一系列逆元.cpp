#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10100000;
int inv[N];
int n, p;
signed main()
{
    scanf("%lld%lld", &n, &p);
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = (p - p / i) * inv[p % i] % p;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", inv[i]);
    }
    return 0;
}