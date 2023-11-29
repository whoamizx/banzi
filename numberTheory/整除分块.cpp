#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, L, R, ans = 0;
    scanf("%lld", &n);
    for (L = 1; L <= n; L = R + 1)
    {
        R = n / (n / L);
        ans += (R - L + 1) * (n / L);
        printf("%lld-%lld:%lld\n", L, R, n / R);
    }
    printf("%lld\n", ans);
    return 0;
}