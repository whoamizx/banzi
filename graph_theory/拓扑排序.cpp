// 最小字典序拓扑排序
#include <bits/stdc++.h>
using namespace std;
vector<int> edge[110];
int n, m, l[110], d[110];
priority_queue<int, vector<int>, greater<int>> q; // 改成小根堆
inline void Toposort()
{
    while (!q.empty())
    {
        q.pop();
    }

    for (int i = 1; i <= n; i++)
    {
        if (!d[i])
        {
            q.push(i);
        }
    }
    int tot = 0;
    while (!q.empty())
    {
        int x = q.top();
        q.pop();
        l[++tot] = x;
        for (auto y : edge[x])
        {
            if (--d[y] == 0)
            {
                q.push(y);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", l[i]);
    }
    printf("\n");
}
int main()
{
    while (scanf("%d%d", &n, &m) == 2 && n) // 此处表示n和m不同时为0
    {
        memset(d, 0, sizeof(d));
        for (int i = 0; i <= n; i++) // 注意多个输入清空
        {
            edge[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            edge[x].push_back(y);
            ++d[y];
        }
        Toposort();
    }
    return 0;
}