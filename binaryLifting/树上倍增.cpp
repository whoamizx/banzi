#include <bits/stdc++.h>
using namespace std;
// 给你一棵有n个节点的树，节点编号从1到n，每个节点有一个点权ai。
// 有q次询问，每次询问两个节点u,v，请问树上从u到v的路径上的点的最小点权是多少。
// 输入格式
// 输入第一行两个整数n,q，表示顶点数和询问数。第二行n个整数表示a。
// 接下来n-1行，每行两个数u,v，表示u、u之间有一条边。
// 接下来q行，每行两个整数u, v代表一次询问。
const int N = 1e5 + 10;
int n, q, a[N];
int dist[N];  // 深度
int f[N][21]; // 每个节点跳2^n步数到达的节点
int v[N][21];
vector<int> edge[N];
inline void dfs(int x)
{
    for (auto y : edge[x])
    {
        if (!dist[y])
        {
            dist[y] = dist[x] + 1; // 初始化深度
            f[y][0] = x;           // 初始化f[][0],节点跳2^0,就是父亲节点
            dfs(y);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &q); // n是节点数
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    // 建树
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    // 初始化深度和跳2^0时的情况
    memset(dist, 0, sizeof(dist));
    dist[1] = 1;
    dfs(1); // 让1为根节点

    // 初始化为最大值,因为要求路上的最小点权
    memset(v, 127, sizeof(v));
    for (int i; i <= n; i++)
    {
        // 节点i跳2^0,不包括终点的路上最小点权就是i本身
        v[i][0] = a[i];
    }

    // 初始化f和v,j节点跳2^i次方,相当于j节点跳2的i-1次方,在跳2的i-1次方
    // 而2的i-1次方已经更新过了
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[j][i] = f[f[j][i - 1]][i - 1];
            v[j][i] = min(v[j][i - 1], v[f[j][i - 1]][i - 1]);
        }
    }
    // 询问
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        // 把深的放前面
        if (dist[x] < dist[y])
        {
            swap(x, y);
        }
        int z = dist[x] - dist[y];
        int ans = 1 << 30;
        // 先拉到一样的深度
        // 快速拉,像快速幂一样,按位拉
        for (int i = 0; z; z /= 2, i++)
        {
            if (z & 1)
            {
                // 拉的过程中也更新最小节点
                ans = min(v[x][i], ans);
                x = f[x][i];
            }
        }

        // x==y时,x或者y就是LCA,否则f[x][0]是
        if (x != y)
        {
            // 一起往上拉
            // 因为是按位的,所以最好一点刚好拉到一起
            for (int i = 20; i >= 0; i--)
            {
                if (f[x][i] != f[y][i])
                {
                    ans = min(ans, v[x][i]);
                    ans = min(ans, v[y][i]);
                    x = f[x][i];
                    y = f[y][i];
                }
            }
            // x和y拉到LCA的儿子
            ans = min(ans, v[x][0]); // 先比较自己的大小
            ans = min(ans, v[y][0]);
            x = f[x][0]; // 拿到LCA
        }
        ans = min(ans, v[x][0]); // 在比较一下LCA节点的大小
        printf("%d\n", ans);
    }
    return 0;
}