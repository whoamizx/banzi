// 求数组中与a异或最大和最小的数字
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int x[N];
int nxt[N * 30][2];
int cnt = 0;
int endid[N * 30];
void insert(int x, int id)
{
    int now = 0;
    for (int i = 30; i >= 0; i--)
    {
        int y = (x >> i) & 1;
        if (!nxt[now][y])
        {
            nxt[now][y] = ++cnt;
        }
        now = nxt[now][y];
    }
    endid[now] = id;
}
// log复杂度内返回数组中与x异或后最小的数
int query_min_id(int x)
{
    int now = 0;
    // int ans=0;
    for (int i = 30; i >= 0; i--)
    {
        int y = (x >> i) & 1;
        if (nxt[now][y])
        {
            now = nxt[now][y];
        }
        else
        {
            now = nxt[now][y ^ 1];
            // ans+=1<<i;
        }
    }
    return endid[now];
}
int query_max_id(int x)
{
    int now = 0;
    // int ans=0;
    for (int i = 30; i >= 0; i--)
    {
        int y = (x >> i) & 1;
        if (nxt[now][y ^ 1])
        {
            now = nxt[now][y ^ 1];
            // ans+=1<<i;
        }
        else
        {
            now = nxt[now][y];
        }
    }
    return endid[now];
}
signed main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &x[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        insert(x[i], i);
    }
    while (q--)
    {
        int a, b;
        scanf("%lld%lld", &a, &b);
        int idmi = query_min_id(a);
        int idmx = query_max_id(a);
    }
    return 0;
}
