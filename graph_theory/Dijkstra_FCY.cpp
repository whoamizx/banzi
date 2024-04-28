#include <bits/stdc++.h>
using namespace std;
#define int long long
// https://pintia.cn/problem-sets/994805046380707840/exam/problems/994805073643683840?type=7&page=0
// 在地图上显示有多个分散的城市和一些连接城市的快速道路。
// 每个城市的救援队数量和每一条连接两个城市的快速道路长度都标在地图上。
// 你的任务尽快赶往事发地，一路上召集尽可能多的救援队。
const int N = 510;
int a[N];   // 点的权值
int dis[N]; // 到起点距离
int cnt[N]; // 路上点权值和
int n, m;
int pre[N];    // 上一个经过的点
int luxian[N]; // 路线
int num[N];    // 方案数
int vis[N];
vector<pair<int, int>> edges[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> st;
void dijkstra(int start, int end)
{
    // 初始化距离
    for (int i = 1; i <= n; i++)
    {
        if (i == start)
        {
            dis[i] = 0;
        }
        else
        {
            dis[i] = LLONG_MAX;
        }
    }
    // 起点塞进优队
    st.push({dis[start], start});
    // 起点召集的救援队
    cnt[start] = a[start];
    // 起点方案数目
    num[start] = 1;
    while (!st.empty())
    {
        auto now = st.top();
        st.pop();
        if (vis[now.second])
        {
            continue;
        }
        vis[now.second] = 1;
        for (auto y : edges[now.second])
        {
            // 路径更短
            // 从now走经过y走过来比之前记录的最短路径短
            if (dis[now.second] + y.first < dis[y.second])
            {
                // 救援队数目加起来
                cnt[y.second] = cnt[now.second] + a[y.second];
                // 更新距离后放入优队
                dis[y.second] = dis[now.second] + y.first;
                st.push({dis[y.second], y.second});
                // 更新上一个走过的点
                pre[y.second] = now.second;
                // 方案数目和上一个相同
                num[y.second] = num[now.second];
            }
            else if (dis[now.second] + y.first == dis[y.second])
            {
                // 路线长度相同,更新方案数
                num[y.second] += num[now.second];
                // 救援队更多才更新救援队数目,并且更新路径
                if (cnt[y.second] < cnt[now.second] + a[y.second])
                {
                    cnt[y.second] = cnt[now.second] + a[y.second];
                    pre[y.second] = now.second;
                }
                st.push({dis[y.second], y.second}); //
            }
        }
    }
    int tot = 0;
    // 从终点倒回去记录路径
    for (int i = end; i != start; i = pre[i])
    {
        luxian[++tot] = i;
    }
    // 输出方案数目和最后最多的救援队数目
    printf("%lld %lld\n", num[end], cnt[end]);
    // 到着输出路径
    printf("%lld ", start - 1);
    for (int i = tot; i != 1; i--)
    {
        printf("%lld ", luxian[i] - 1);
    }
    printf("%lld", end - 1);
    printf("\n");
}
signed main()
{
    int s, d;
    scanf("%lld%lld%lld%lld", &n, &m, &s, &d);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        u++;
        v++;
        edges[u].push_back({w, v});
        edges[v].push_back({w, u});
    }
    s++;
    d++;
    dijkstra(s, d);
    return 0;
}