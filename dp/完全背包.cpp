// 完全背包
// 每个物品无数个
#include <bits/stdc++.h>
using namespace std;
int n, m, p[1001], v[1001], w[1001];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &w[i]);
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            p[j] = max(p[j], p[j - v[i]] + w[i]);
    printf("%d\n", p[m]);
}