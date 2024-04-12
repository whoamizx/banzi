#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e8 + 10;
vector<int> prime;
bool vis[M];
// 每个合数只被最小的质因数筛一次
int euler_sieve(int n)
{
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            cnt++;
        }
        for (int j = 0; j < cnt; j++)
        {
            if (i * prime[j] > n)
            {
                break;
            }
            // 每个prime的i倍都被筛,i递增的
            vis[i * prime[j]] = 1;
            // 防止重复筛
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
