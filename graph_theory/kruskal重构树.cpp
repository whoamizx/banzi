// O(mlog(m))的kruskal加倍增的复杂度
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10; // 点数的两倍
const int M = 6e5 + 10; // 边数的两倍

struct Node
{
    int x, y, v;
} a[M];

int n, m, q, tot, fa[N], nodeweigh[N], dist[N], f[N][21];
vector<int> edge[N];
vector<int> node[N];

bool cmp(Node A, Node B) // 从小或者从大生成
{
    return A.v > B.v; // 最小值最大
    //<最大值最小
}

int findset(int i)
{
    if (i == fa[i])
        return i;
    // 记得更新fa[i],让下次查找更快
    return fa[i] = findset(fa[i]);
}

void kruskal_rebuild_tree()
{
    tot = n; // 节点数目

    for (int i = 1; i <= 2 * n; i++) // 点数增加
        fa[i] = i;

    sort(a + 1, a + 1 + m, cmp);
    int cnt = n;
    for (int i = 1; i <= m; i++)
    {
        int x = findset(a[i].x);
        int y = findset(a[i].y);
        if (x != y)
        {
            tot++;
            fa[x] = tot;
            fa[y] = tot;
            node[tot].push_back(x);
            node[tot].push_back(y);
            nodeweigh[tot] = a[i].v;
            --cnt;
        }
        // 稍微降低一点复杂度,因为n次建树之后,所有点肯定用完了
        // 而边的数目多,所以后面的边直接break
        if (cnt == 1)
            break;
    }
    n = tot; ////更新n
}

inline void dfs(int x) // 双向边的话要判from //?
{
    for (auto y : node[x]) //////
    {
        if (!dist[y])
        {
            dist[y] = dist[x] + 1;
            f[y][0] = x;
            dfs(y);
        }
    }
}

int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
    }

    kruskal_rebuild_tree();

    memset(dist, 0, sizeof(dist));
    // 可能有多棵树,形成森林
    bool bb[n];
    bb[n] = true;
    // n一定是一个根节点,因为n已经更新了,变成重构树的最上面的根节点
    dist[n] = 1;
    dfs(n);

    for (int i = 1; i <= n; i++)
    {
        int father = findset(i);
        // 看这片森林的这棵树有没有访问过
        if (!bb[father])
        {
            // 从根节点开始,更新这颗树的深度
            dist[father] = 1;
            dfs(father);
            bb[father] = true; // 只有把father设成true就行,dfs就不要麻烦了
        }
    }

    for (int i = 1; i <= 20; i++) // 先遍历完所有节点的一2^i父亲,再下一层
    {
        for (int j = 1; j <= n; j++)
        {
            f[j][i] = f[f[j][i - 1]][i - 1];
        }
    }

    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (findset(x) != findset(y))
        {
            printf("-1\n");
            continue;
        }
        if (dist[x] < dist[y])
        {
            swap(x, y);
        }
        int z = dist[x] - dist[y];
        for (int i = 0; z; z /= 2, i++)
        {
            if (z & 1)
            {
                x = f[x][i];
            }
        }
        if (x != y) // x==y时,x或者y就是LCA,否则f[x][0]是
        {
            for (int i = 20; i >= 0; i--)
            {
                if (f[x][i] != f[y][i])
                {
                    x = f[x][i];
                    y = f[y][i];
                }
            }
            x = f[x][0]; // 放括号里面
        }
        printf("%d\n", nodeweigh[x]);
    }
    return 0;
}