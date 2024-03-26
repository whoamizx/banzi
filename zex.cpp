// Problem: P9233 [蓝桥杯 2023 省 A] 颜色平衡树
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P9233
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x, y, z) for (int x = (y); x <= (z); x++)
#define per(x, y, z) for (int x = (y); x >= (z); x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s)                       \
    do                                  \
    {                                   \
        freopen(s ".in", "r", stdin);   \
        freopen(s ".out", "w", stdout); \
    } while (false)
#define likely(exp) __builtin_expect(!!(exp), 1)
#define unlikely(exp) __builtin_expect(!!(exp), 0)
using namespace std;
typedef long long ll;

mt19937 rnd(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
int randint(int L, int R)
{
    uniform_int_distribution<int> dist(L, R);
    return dist(rnd);
}

template <typename T>
void chkmin(T &x, T y)
{
    if (x > y)
        x = y;
}
template <typename T>
void chkmax(T &x, T y)
{
    if (x < y)
        x = y;
}

const int N = 2e5 + 5;

int n, c[N], f[N], sz[N], son[N], cnt[N], ccnt[N], ans;
vector<int> e[N];

void dfs(int u)
{
    sz[u] = 1;
    for (int v : e[u])
    {
        dfs(v);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]])
            son[u] = v;
    }
}

void add(int u, int dt)
{
    --ccnt[cnt[c[u]]];
    cnt[c[u]] += dt;
    ++ccnt[cnt[c[u]]];
    for (int v : e[u])
        add(v, dt);
}

void calc(int u, bool save)
{
    for (int v : e[u])
        if (v != son[u])
            calc(v, false);
    if (son[u])
        calc(son[u], true);
    --ccnt[cnt[c[u]]];
    ++cnt[c[u]];
    ++ccnt[cnt[c[u]]];
    for (int v : e[u])
        if (v != son[u])
            add(v, 1);
    if (cnt[c[u]] * ccnt[cnt[c[u]]] == sz[u])
        ++ans;
    if (!save)
        add(u, -1);
}

int main()
{
    scanf("%d", &n);
    rep(i, 1, n)
    {
        scanf("%d%d", &c[i], &f[i]);
        if (f[i])
            e[f[i]].push_back(i);
    }
    dfs(1);
    calc(1, true);
    printf("%d\n", ans);
    return 0;
}