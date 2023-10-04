#include <bits/stdc++.h>
using namespace std;
// 给你N个数字h , h2,... , hx，你需要进行一些操作使这些数字变得都一样大，
// 操作如下:
// ·使任意一个数字+1，代价为A;
// ·使任意一个数字-1，代价为R;
// ·使任意一个数字―1并让另一个数字＋1，代价为M。
// 现在问你将这些数字变成一样的最小代价为多少。
const int N = 1e5 + 10;
int n, a[N], A, r, M;
long long f(int x)
{
    long long y = 0, z = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= x)
        {
            y += x - a[i];
        }
        else
        {
            z += a[i] - x;
        }
    }
    long long res = min(y, z) * M;
    if (y > z)
    {
        res += (y - z) * A;
    }
    else
    {
        res += (z - y) * r;
    }
    return res;
}
int main()
{
    scanf("%d%d%d%d", &n, &A, &r, &M);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    M = min(M, A + r);
    int L = 0, R = 1e9;
    while (L + 2 < R)
    {
        int M1 = (R - L) / 3 + L;
        int M2 = (R - L) / 3 * 2 + L;
        if (f(M1) > f(M2))
        {
            L = M1;
        }
        else
        {
            R = M2;
        }
    }
    long long ans = f(L);
    for (int i = L + 1; i <= R; i++)
    {
        ans = min(ans, f(i));
    }
    printf("%lld\n", ans);
    return 0;
}