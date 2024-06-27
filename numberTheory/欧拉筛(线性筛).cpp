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
            vis[i * prime[j]] = 1;
            // 如果i%prime[j]==0,说明i是合数,i=k*prime[j]
            // 如果继续往后遍历,则会筛掉i*prime[j+1]
            // 但是i*prime[j+1],应该被prime[j]筛掉
            // 因为i*prime[j+1]=k*prime[j]*prime[j+1]
            // 这里就会重复筛,所以break
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
