#include <bits/stdc++.h>
using namespace std;
// 给出一个N次函数，保证在范围[l,r]内存在一点a，使得[l, a]上单调增，[a,r]上单调减
// 试求出a的值
double a[20];
int n;
double f(double x)
{
    double res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = (res + a[i]) * x;
    }
    return res + a[n + 1];
}
int main()
{
    cin >> n;
    double L, R;
    scanf("%lf%lf", &L, &R);
    for (int i = 1; i <= n + 1; i++)
    {
        scanf("%lf", &a[i]);
    }
    for (int i = 1; i <= 100; i++)
    {
        double M1 = (R - L) / 3 + L;
        double M2 = (R - L) / 3 * 2 + L;
        if (f(M1) < f(M2))
        {
            L = M1;
        }
        else
        {
            R = M2;
        }
    }
    printf("%.10f\n", L);
    return 0;
}