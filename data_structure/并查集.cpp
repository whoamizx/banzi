#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int fa[N];
int Findset(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    return fa[x] = Findset(fa[x]);
}
void merge(int x, int y)
{
    int fx = Findset(x), fy = Findset(y);
    if (fx == fy)
    {
        return;
    }
    fa[fx] = fy;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> z >> x >> y;
        if (z == 1)
        {
            merge(x, y);
        }
        else
        {
            if (Findset(x) == Findset(y))
            {
                printf("Y\n");
            }
            else
            {
                printf("N\n");
            }
        }
    }
    return 0;
}