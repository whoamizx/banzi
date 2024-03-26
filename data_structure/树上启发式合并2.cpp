#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
// 好理解的启发式合并
int c[N];
vector<int> edges[N];
int sz[N];
int son[N];
int ans;
int cnt[N];
int ccnt[N];

void dfs(int cur)
{
    sz[cur] = 1;
    for (auto y : edges[cur])
    {
        dfs(y);
        sz[cur] += sz[y];
        if (sz[y] > sz[son[cur]])
        {
            son[cur] = y;
        }
    }
}
void add(int u, int dt)
{
    --ccnt[cnt[c[u]]];
    cnt[c[u]] += dt;
    ++ccnt[cnt[c[u]]];
    for (auto v : edges[u])
    {
        add(v, dt);
    }
}
void calc(int u, bool save)
{
    // 更新轻儿子,不保留信息
    for (auto v : edges[u])
    {
        if (v != son[u])
        {
            calc(v, false);
        }
    }
    // 更新重儿子,保留信息
    if (son[u])
    {
        calc(son[u], true);
    }

    // 用自己更新
    --ccnt[cnt[c[u]]];
    ++cnt[c[u]];
    ++ccnt[cnt[c[u]]];
    // 用轻儿子更新
    // 这时自己,轻重儿子的信息就全了
    for (auto v : edges[u])
    {
        if (v != son[u])
        {
            add(v, 1);
        }
    }
    // 记录答案,这里O(n)就是n方logn,这里O(1)就是nlogn
    if (cnt[c[u]] * ccnt[cnt[c[u]]] == sz[u])
    {
        ans++;
    }

    // 如果这个节点不要保留,抹去他全部的贡献//自己,轻儿子和重儿子
    if (!save)
    {
        add(u, -1);
    }
}

signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int father;
        scanf("%lld%lld", &c[i], &father);
        edges[father].push_back(i);
    }
    // 重链剖分
    dfs(1);
    calc(1, true);
    printf("%lld\n", ans);
    return 0;
}