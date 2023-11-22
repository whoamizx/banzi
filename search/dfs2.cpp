/*判断海水上涨后几个岛屿会被淹没,p106算法竞赛*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char mp[N][N];
int vis[N][N] = {0};
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int flag;
void dfs(int x, int y)
{
    vis[x][y] = 1;
    if (mp[x][y + 1] == '#' && mp[x][y - 1] == '#' && mp[x + 1][y] == '#' && mp[x - 1][y] == '#')
    {
        flag = 1;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (vis[nx][ny] == 0 && mp[nx][ny] == '#')
        {
            dfs(nx, ny);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", mp[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j] == '#' && vis[i][j] == 0)
            {
                flag = 0;
                dfs(i, j);
                if (flag == 0)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}