#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n;
int ai[N], mi[N];
// long long 乘法取模
int mul(int a, int b, int m)
{
    int res = 0;
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
int extend_gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int excrt()
{
    int x, y;
    int m1 = mi[1], a1 = ai[1];
    int ans = 0;
    for (int i = 2; i <= n; i++) // n
    {
        int a2 = ai[i], m2 = mi[i];
        int a = m1, b = m2, c = (a2 - a1 % m2 + m2) % m2;
        int d = extend_gcd(a, b, x, y);
        if (c % d != 0)
        {
            return -1; // return 的值
        }
        x = mul(x, c / d, b / d);
        ans = a1 + x * m1;
        m1 = m2 / d * m1;
        ans = (ans % m1 + m1) % m1;
        a1 = ans;
    }
    return ans;
}
// x=ai(mod mi)
signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &mi[i], &ai[i]);
    }
    printf("%lld\n", excrt());
    return 0;
}