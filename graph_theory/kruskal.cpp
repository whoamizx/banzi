// O(mlog(m))
#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
const int M = 2e5 + 10;
struct Node
{
    int x, y, v;
    bool operator<(const Node &A)
    {
        return v < A.v;
    }
} a[M];
int n, m, fa[N];
int findset(int i)
{
    if (i == fa[i])
    {
        return i;
    }
    return fa[i] = findset(fa[i]);
}
int kruskal()
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    sort(a + 1, a + 1 + m);
    int ans = 0, cnt = n;
    for (int i = 1; i <= m; i++)
    {
        int x = findset(a[i].x);
        int y = findset(a[i].y);
        if (x != y)
        {
            fa[x] = y;
            ans += a[i].v;
            --cnt;
        }
        if (cnt == 1)
        {
            break;
        }
    }
    if (cnt != 1)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
    }
    int ans = kruskal();
    if (ans == -1)
    {
        printf("orz\n");
    }
    else
    {
        printf("%d\n", ans);
    }
    return 0;
}