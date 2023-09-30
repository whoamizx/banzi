// 多重背包
// 每个物品有数量
#include <bits/stdc++.h>
using namespace std;
int n, m, p[2001], v[2001], w[2001], l[2001];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &v[i], &w[i], &l[i]);
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= n; i++)
    {
        int res = l[i];
        for (int k = 1; k <= res; res -= k, k *= 2)
            // 每个数都可以拆成1 2 4 ..2^m n-2^m
            for (int j = m; j >= v[i] * k; j--)
                p[j] = max(p[j], p[j - v[i] * k] + w[i] * k);
        for (int j = m; j >= v[i] * res; j--)
            p[j] = max(p[j], p[j - v[i] * res] + w[i] * res);
    }
    printf("%d\n", p[m]);
}