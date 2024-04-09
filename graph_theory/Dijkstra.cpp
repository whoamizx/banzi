// O(mlog(n)+nklog(n))//k为每个点的平均邻居数
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
set<pair<int, int>> q;          // 点数
vector<pair<int, int>> edge[N]; // 点数
int n, m, dist[N];              // n和m的取值需要注意
int Dijkstra(int s, int t)
{
    // 初始化成大数
    // 大于1<<30// long long 时候需要修改
    // 可以改成用for
    memset(dist, 127, sizeof(dist));
    dist[s] = 0;
    q.clear();
    // 初始化
    for (int i = 1; i <= n; i++)
    {
        q.insert({dist[i], i});
    }

    while (!q.empty())
    {
        int x = q.begin()->second;
        q.erase(q.begin());
        // 到终点或者访问过的点用完了,1<<30比较相当于vis数组
        if (x == t || dist[x] > 1 << 30) // long long 时候需要修改
        {
            break;
        }
        for (auto y : edge[x])
        {
            // 从x出发经过y边到y的终点,如果比之前记录的小,就更新
            if (dist[x] + y.second < dist[y.first])
            {
                q.erase({dist[y.first], y.first});
                dist[y.first] = dist[x] + y.second;
                q.insert({dist[y.first], y.first});
            }
        }
    }
    return dist[t];
}
int main()
{
    int s;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        // 有向图
        edge[u].push_back({v, w});
    }
    Dijkstra(s, 0);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dist[i]);
    }
    return 0;
}