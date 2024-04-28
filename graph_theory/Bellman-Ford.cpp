// O(n,m)
// 带负权的单源最短路
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
const int M = 1e4 + 10;
int n, m, cnt;
int pre[N];
struct edge
{
    int u, v, w;
} e[M];
// 打印路径
void print_path(int s, int t)
{
    if (s == t)
    {
        printf("%lld ", s);
        return;
    }
    print_path(s, pre[t]);
    printf("%lld ", t);
}
void bellman()
{
    // 起点
    int s = 1;
    // 距离数组
    int d[N];
    for (int i = 1; i <= n; i++)
    {
        d[i] = LLONG_MAX / 2;
    }
    d[s] = 0;
    // 可以通过ok控制迭代次数
    for (int k = 1; k <= n; k++)
    {
        int ok = 1;
        for (int i = 1; i <= cnt; i++)
        {
            // u到v的一条边更新
            int x = e[i].u;
            int y = e[i].v;
            if (d[y] > d[x] + e[i].w)
            {
                d[y] = d[x] + e[i].w;
                pre[y] = x;
                ok = 0;
            }
        }
        if (ok)
        {
            break;
        }
    }
    // 终点为n
    printf("%lld\n", d[n]);
    // print_path(s,n);
}
signed main()
{
    while (~scanf("%lld%lld", &n, &m))
    {
        if (n == 0 && m == 0)
        {
            return 0;
        }
        cnt = 0;
        while (m--)
        {
            int a, b, c;
            scanf("%lld%lld%lld", &a, &b, &c);
            cnt++;
            e[cnt].u = a;
            e[cnt].v = b;
            e[cnt].w = c;
            cnt++;
            e[cnt].u = b;
            e[cnt].v = a;
            e[cnt].w = c;
        }
        bellman();
    }
    return 0;
}