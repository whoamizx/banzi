#include <bits/stdc++.h>
using namespace std;
// 数轴上有n个人，他们要选一个地点集合。第i个人初始在位置a;上，他的移速最大是b
// 请问最少需要花费多少秒，这n个人可以在某一个点集合。
const int N = 1e5 + 10;
int n, a[N], b[N];
// 求交集
bool check(double x)
{
    double L = -1e10, R = 1e10;
    for (int i = 1; i <= n; i++)
    {
        double l = a[i] - b[i] * x, r = a[i] + b[i] * x;
        L = max(L, l);
        R = min(r, R);
    }
    if (L > R)
    {
        return false;
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    double L = 0, R = 50010;
    // 小数二分,写死次数,保证精度
    for (int i = 1; i <= 100; i++)
    {
        double M = (L + R) / 2;
        if (check(M))
        {
            R = M;
        }
        else
        {
            L = M;
        }
    }
    printf("%.10f\n", R);
    return 0;
}