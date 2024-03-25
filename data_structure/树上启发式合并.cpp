#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
// 经常和树上什么颜色问题有关系
int color[N];
vector<int> edges[N];
int siz[N];
int son[N];
int ans[N];
int cnt[N];
int flag;
int maxc;
int sum;
// 重链剖分,找出每个节点的重儿子
void dfs1(int x, int father)
{
    siz[x] = 1;
    for (auto y : edges[x])
    {
        if (y != father)
        {
            dfs1(y, x);
            siz[x] += siz[y];
            if (siz[son[x]] < siz[y])
            {
                son[x] = y;
            }
        }
    }
}

void count(int u, int f, int val)
{
    cnt[color[u]] += val;

    if ((cnt[color[u]] > maxc))
    {
        maxc = cnt[color[u]];
        sum = color[u];
    }
    else if (cnt[color[u]] == maxc)
    {
        sum += color[u];
    }

    for (auto y : edges[u])
    {
        // 这里就只略去之前在处理节点的重儿子,所以就只略去一个重儿子
        if (y == f || y == flag)
        {
            continue;
        }
        count(y, u, val);
    }
}
// keep,是否保留信息
void dfs(int u, int f, bool keep)
{
    // 处理轻儿子,不保留信息
    for (auto y : edges[u])
    {
        if (y == f || y == son[u])
        {
            continue;
        }
        dfs(y, u, false);
    }
    // 如果有重儿子,就处理重儿子,并且保留信息
    if (son[u])
    {
        dfs(son[u], u, true);
        // 把本节点的重儿子是谁记录下来
        flag = son[u];
    }
    // 本题特定的算答案函数
    count(u, f, 1);
    // 这个轻儿子节点处理完了,他的自己和他的重儿子的信息也要全部删掉,
    // 所以flag=0,防止没有删去这个轻儿子节点的重儿子信息
    flag = 0;
    ans[u] = sum;
    if (!keep)
    {
        // 不保留轻儿子信息,删去轻儿子信息
        count(u, f, -1);
        sum = maxc = 0;
    }
}
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &color[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs1(1, -1);
    dfs(1, -1, 0);
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", ans[i]);
    }
    return 0;
}