#include <bits/stdc++.h>
using namespace std;
#define int long long
int mul(int x, int y, int m)
{
    x % m;
    y % m;
    int d = ((long double)x * y / m);
    d = x * y - d * m;
    if (d >= m)
        d -= m;
    if (d < 0)
        d += m;
    return d;
}
signed main()
{
    int x, y, m;
    scanf("%lld%lld%lld", &x, &y, &m);
    printf("%lld\n", (x % m * y % m) % m);
    printf("%lld\n", mul(x, y, m));
    return 0;
}