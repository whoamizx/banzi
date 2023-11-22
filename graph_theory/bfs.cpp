#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, dist[N];
int q[N]; // 队列
vector<int> edge[N + 1];
void bfs(int s)
{
    memset(dist, 255, sizeof(dist)); // 设为-1
    dist[s] = 0;
    int front = 1, rear = 1;
    q[1] = s;
    while (front <= rear)
    {
        int x = q[front];
        ++front;
        for (auto y : edge[x])
        {
            if (dist[y] == -1)
            {
                dist[y] = dist[x] + 1;
                q[++rear] = y;
            }
        }
    }
}

int main()
{

    return 0;
}