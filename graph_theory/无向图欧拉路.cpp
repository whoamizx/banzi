#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10; // 边数乘2
struct Node
{
    int y, idx;
    Node(int _y, int _idx) : y(_y), idx(_idx) {}
};
vector<Node> edge[N];
int n, m, cnt = 1, l, f[N], c[N], d[N];
bool b[N];
inline void dfs(int x)
{
    while (f[x] < d[x])
    {
        int y = edge[x][f[x]].y;
        int idx = edge[x][f[x]].idx;
        if (!b[idx])
        {
            ++f[x];
            b[idx] = b[idx ^ 1] = true; // 每条双向边走一次
            dfs(y);
            c[++l] = y;
        }
        else
        {
            ++f[x];
        }
    }
}
inline void Euler()
{
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] & 1)
        {
            ++y, x = i;
        }
    }
    if (y && y != 2)
    {
        printf("No\n");
        return;
    }
    if (!x)
    {
        for (int i = 1; i <= n; i++)
        {
            if (d[i])
            {
                x = i;
            }
        }
    }
    memset(b, false, sizeof(b));
    memset(f, 0, sizeof(f));
    l = 0;
    dfs(x);
    c[++l] = x; // 从x开始
    if (l != m + 1)
    {
        printf("No\n");
        return;
    }
    for (int i = l; i >= 1; i--) // 输出边
    {
        printf("%d\n", c[i]);
    }
    return;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        edge[x].push_back(Node(y, ++cnt));
        edge[y].push_back(Node(x, ++cnt));
        ++d[x];
        ++d[y];
    }
    Euler();
    return 0;
}