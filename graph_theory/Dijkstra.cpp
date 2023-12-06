// O(mlog(n))
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node
{
    int y, v;
    Node(int _y, int _v)
    {
        y = _y;
        v = _v;
    }
};
set<pair<int, int>> q;
vector<Node> edge[N + 1];
int n, m, dist[N + 1]; // n和m的取值需要注意
int Dijkstra(int s, int t)
{
    memset(dist, 127, sizeof(dist)); // 大于1<<30
    dist[s] = 0;
    q.clear();
    for (int i = 1; i <= n; i++)
    {
        q.insert(make_pair(dist[i], i));
    }
    while (!q.empty())
    {
        int x = q.begin()->second;
        q.erase(q.begin());
        if (x == t || dist[x] > 1 << 30) // long long 时候需要修改
        {
            break;
        }
        for (auto i : edge[x])
        {
            if (dist[x] + i.v < dist[i.y])
            {
                q.erase(make_pair(dist[i.y], i.y));
                dist[i.y] = dist[x] + i.v;
                q.insert(make_pair(dist[i.y], i.y));
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
        cin >> u >> v >> w;
        edge[u].push_back(Node(v, w));
    }
    Dijkstra(s, 0);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dist[i]);
    }
    return 0;
}