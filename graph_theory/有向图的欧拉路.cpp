#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 4e5 + 10;
vector<int> edge[N];
int n, m, l, f[N], ind[N], outd[N], c[M];
inline void dfs(int x)
{
    while (f[x] < outd[x])
    {
        int y = edge[x][f[x]];
        ++f[x];
        dfs(y);
        c[++l] = y;
    }
}
inline void Euler()
{
    int x = 0, y = 0, z = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] + 1 == outd[i])
        {
            x = i;
            y++;
        }
        if (ind[i] != outd[i])
        {
            z++;
        }
    }
    if (!((y == 1 && z == 2) || !z))
    {
        printf("No\n");
        return;
    }
    if (!x)
    {
        for (int i = 1; i <= n; i++)
        {
            if (ind[i])
            {
                x = i;
                break;
            }
        }
    }
    memset(f, 0, sizeof(f));
    l = 0;
    dfs(x);
    c[++l] = x;
    if (l != m + 1)
    {
        printf("No\n");
        return;
    }
    for (int i = l; i; i--)
    {
        printf("%d ", c[i]);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        ind[y]++;
        outd[x]++;
    }
    for (int i = 1; i <= n; i++) // 最小字典序输出
    {
        sort(edge[i].begin(), edge[i].end());
    }
    Euler();
    return 0;
}