// O(n^3)
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const double eps = 1e-10;
int n;
double a[N][N], b[N];
inline int gauss()
{
    int l = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = l; j <= n; j++)
        {
            // 0不能作为第一列,所以找一个非0的上来
            if (a[j][i])
            {
                for (int k = i; k <= n; k++)
                {
                    swap(a[j][k], a[l][k]);
                }
                swap(b[j], b[l]);
                break;
            }
        }
        if (fabs(a[l][i]) < eps) // double判是否为0
        {
            continue; // continue之后l没有更新,所以可以判断自由元的个数
            // 虽然l没有更新,上面也可以用了继续消元,就不能用i了
        }
        for (int j = 1; j <= n; j++)
        {
            if (j != l)
            {
                double delta = a[j][i] / a[l][i];
                for (int k = i; k <= n; k++)
                {
                    a[j][k] -= a[l][k] * delta;
                }
                b[j] -= b[l] * delta;
            }
        }
        l++;
    }
    // 有参数没搞完
    for (int i = l; i <= n; i++)
    {
        if (fabs(b[i]) > eps)
        {
            // 无解
            return -1;
        }
    }
    if (l <= n)
    {
        // 无穷多解
        return -2;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%.2lf\n", b[i] / a[i][i]);
        }
    }
    return 0;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%lf", &a[i][j]);
        }
        scanf("%lf", &b[i]);
    }
    int ans = gauss();
    if (ans == -1 || ans == -2)
    {
        printf("No Solution\n");
    }
    return 0;
}