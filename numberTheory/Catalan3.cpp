#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[210];
signed main()
{
    int n;
    cin >> n;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            f[i] += f[j] * f[i - j - 1];
            f[i] %= 100;
        }
    }
    printf("%lld\n", f[n]);
    return 0;
}