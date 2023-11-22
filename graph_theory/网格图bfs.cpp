#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 1010;
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, dist[N + 1][M + 1], q[N * M][2];
char s[N + 1][M + 1];
void bfs(int sx, int sy)
{
    memset(dist, 255, sizeof(dist));
    dist[sx][sy] = 0;
    int front = 1, rear = 1;
    q[1][0] = sx;
    q[1][1] = sy;
    while (front <= rear)
    {
        int x = q[front][0], y = q[front][1];
        ++front;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + D[i][0], yy = y + D[i][1];
            if (xx < 1 || xx > n || yy < 1 || yy > m)
                continue;
            if (s[xx][yy] != 'X' && dist[xx][yy] == -1)
            {
                dist[xx][yy] = dist[x][y] + 1;
                q[++rear][0] = xx, q[rear][1] = yy;
            }
        }
    }
}
int main()
{

    return 0;
}