// 手写队列
#include <bits/stdc++.h>
using namespace std;
// 给你n个数a , ...., a,和一个整数k，你需要在这n个数中选出连续的c个数，
// 使得这c个数的最大值不超过k，请问有几种选法。
const int N = 1e6 + 10;
int n, k, c, a[N], q[N];
int main()
{
    cin >> n >> k >> c;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int front = 1, rear = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (front <= rear && a[q[rear]] <= a[i])
        {
            --rear;
        }
        q[++rear] = i;
        if (i - c + 1 >= 1)
        {
            if (a[q[front]] <= k)
            {
                ans++;
            }
            if (q[front] == i - c + 1)
            {
                front++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}