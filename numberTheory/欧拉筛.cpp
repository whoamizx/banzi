#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 10;
const int M = 1e8 + 10;
// 从0开始
int prime[N];
bool vis[M];
int euler_sieve(int n)
{
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            prime[cnt] = i;
            cnt++;
        }
        for (int j = 0; j < cnt; j++)
        {
            if (i * prime[j] > n)
            {
                break;
            }
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    return cnt;
}
signed main()
{
    int n, q;
    scanf("%lld%lld", &n, &q);
    euler_sieve(n);
    while (q--)
    {
        int temp;
        scanf("%lld", &temp);
        printf("%lld\n", prime[temp - 1]);
    }
    return 0;
}
