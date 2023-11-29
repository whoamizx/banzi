#include <bits/stdc++.h>
using namespace std;
#define int long long
// 参数必须是正的
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
signed main()
{
    int x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    int a = n - m;
    int b = L;
    int c = x - y;
    if (a < 0)
    {
        a = -a;
        c = -c;
    }
    int tempx, tempy;
    int d = extend_gcd(a, b, tempx, tempy);
    if (c % d != 0)
    {
        printf("Impossible\n");
    }
    else
    {
        int xx = tempx * (c / d);
        int bb = b / d;
        x = (xx % bb + bb) % bb; // 最小整数解
        printf("%lld\n", x);
    }
    return 0;
}