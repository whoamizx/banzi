#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> edge[N];
int n, m, c[N];
bool dfs(int x)
{
    for (auto y : edge[x])
    {
        if (!c[y])
        {
            c[y] = 3 - c[x];
            if (!dfs(y))
            {
                return false;
            }
        }
        else if (c[x] == c[y])
        {
            return false;
        }
    }
    return true;
}
bool check()
{
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        if (!c[i])
        {
            c[i] = 1;
            if (!dfs(i))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    if (check())
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}