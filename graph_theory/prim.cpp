// O(n方+m)
// 裸prim,堆优化prim一般写kruskal
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node
{
    int y, v;
    Node(int _y, int _v) : y(_y), v(_v) {}
};
vector<Node> edge[N];
int n, m;
bool b[N];
int dist[N];
void prim()
{
    memset(dist, 127, sizeof(dist)); // long long change
    memset(b, false, sizeof(b));
    dist[1] = 0;
    int ans = 0;
    int tot = 0;
    while (1)
    {
        int x = -1;
        // 找到一个没有访问过的顶点,并且距离不是无穷大,就是
        // prim中没加入已选的集合中可达的选择一个最小的可达的
        for (int i = 1; i <= n; i++)
        {
            if (!b[i] && dist[i] < 1 << 30) // long long 的时候修改
            {
                if (x == -1 || dist[i] < dist[x])
                {
                    x = i;
                }
            }
        }
        if (x == -1)
        {
            break;
        }
        b[x] = 1;
        // 加上到这个最近点的距离
        ans += dist[x];
        tot++;
        // 用新加入的点更新到其他点的距离
        for (auto i : edge[x])
        {
            dist[i.y] = min(dist[i.y], i.v);
        }
    }
    // 联通与否
    if (tot == n)
    {
        printf("%d\n", ans);
    }
    else
    {
        cout << "orz" << endl;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        edge[x].push_back(Node(y, v));
        edge[y].push_back(Node(x, v));
    }
    prim();
    return 0;
}