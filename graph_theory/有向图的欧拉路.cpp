// https://www.luogu.com.cn/problem/P7771
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 4e5 + 10;
vector<int> edge[N];
int n, m;
// 路径上有几个点了
int l;
// 记录出度用了几个了
int f[N];
// 出度入度
int ind[N], outd[N];
// 记录路径
int c[M];
inline void dfs(int x)
{
    // 出度没用完
    while (f[x] < outd[x])
    {
        // 从上次记录的位置接着往后用
        int y = edge[x][f[x]];
        ++f[x];
        dfs(y);
        // 起点最后才记录,说明要逆序输出
        c[++l] = y;
    }
}
inline void Euler()
{
    // 起点
    int x = 0;
    // 有几个起点
    int y = 0;
    // 有几个出度和入度不相等的点
    int z = 0;
    for (int i = 1; i <= n; i++)
    {
        // 找到出度比入度大1的点,就是起点
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
    // 只有一个起点,并且出度入度不相等的恰有两个,即一个起点一个终点
    // 或者没有出度入度不相等的点也行,否则输出NO
    if (!((y == 1 && z == 2) || !z))
    {
        printf("No\n");
        return;
    }
    // 如果没有起点
    // 第一个有入度的点作为起点
    if (!x)
    {
        for (int i = 1; i <= n; i++)
        {
            if (outd[i])
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
    // 有边没走完
    if (l != m + 1)
    {
        printf("No\n");
        return;
    }
    // 逆序输出
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
        outd[x]++;
        ind[y]++;
    }
    // 给每个点连接的点排序,以输出最小字典序
    for (int i = 1; i <= n; i++) // 最小字典序输出
    {
        sort(edge[i].begin(), edge[i].end());
    }
    Euler();
    return 0;
}