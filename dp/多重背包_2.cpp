// 超大范围多重背包
//https://zhuanlan.zhihu.com/p/430195885
#include <bits/stdc++.h>
using namespace std;
int n, a[100001], b[100001], c[100001][2];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i], &b[i]);
    int k = 0, l = 1;
    for (int i = 1; i <= n; i++)
    {
        for (; k >= l && b[i] >= c[k][0]; --k)
            ;
        c[++k][0] = b[i];
        c[k][1] = a[i];
        printf("%d\n", c[l][0]);
        for (; k >= l && c[l][1] == i; ++l)
            ;
    }
    
}