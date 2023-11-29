#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 10;
int prime[N];
bool vis[N];
int euler_sieve(int n)
{
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt; j++)
        {
            if (i * prime[j] > n)
                break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    return cnt;
}
int main()
{
    int n, q;
    cin >> n >> q;
    euler_sieve(n);
    for (int i = 1; i <= q; i++)
    {
        int temp;
        scanf("%d", &temp);
        printf("%d\n", prime[temp - 1]);
    }
    return 0;
}