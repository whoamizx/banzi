// 分组背包
// 每组只能选一个
#include <bits/stdc++.h>
using namespace std;
int n, m, v[1001], w[1001], a[1001], p[1001];
vector<int> c[1001];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &a[i], &v[i], &w[i]);
        c[a[i]].push_back(i);
    }
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= 1000; i++)
        for (int j = m; j >= 0; j--)
            for (auto k : c[i])
                if (v[k] <= j)
                    p[j] = max(p[j], p[j - v[k]] + w[k]);
    printf("%d\n", p[m]);
}