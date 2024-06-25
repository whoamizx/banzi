#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10; // 边数乘2
// 边的终点和编号
struct Node
{
    int y, idx;
    Node(int _y, int _idx) : y(_y), idx(_idx) {}
};
vector<Node> edge[N];
int n, m;
int cnt = 1;
// 记录走了几条边了
int l;
// 走过的度数
int f[N];
// 记录路径
int c[N];
// 度数
int d[N];
// 记录边走过没有
bool b[N];
inline void dfs(int x)
{
    while (f[x] < d[x])
    {
        // 从上次走过的位置开始
        int y = edge[x][f[x]].y;
        int idx = edge[x][f[x]].idx;
        // 走过就不走了
        if (!b[idx])
        {
            ++f[x];
            // 每条双向边走一次
            //^可以得到边的对应另一条
            b[idx] = b[idx ^ 1] = true;
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
    // 起点
    int x = 0;
    // 有几个奇度顶点
    int y = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] & 1)
        {
            ++y;
            x = i;
        }
    }
    // 没有奇度顶点或者只有两个,否则NO
    if (y && y != 2)
    {
        printf("No\n");
        return;
    }
    // 如果没有起点,随便找一个有度数的点
    if (!x)
    {
        for (int i = 1; i <= n; i++)
        {
            if (d[i])
            {
                x = i;
                break;
            }
        }
    }

    memset(b, false, sizeof(b));
    memset(f, 0, sizeof(f));
    l = 0;
    dfs(x);

    c[++l] = x; // 从x开始
    // 边没走完
    if (l != m + 1)
    {
        printf("No\n");
        return;
    }
    // 逆序输出边
    for (int i = l; i >= 1; i--)
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