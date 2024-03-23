#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int a[N];
signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    int max_so_far1 = a[1];
    int max_end_here1 = a[1];
    for (int i = 2; i <= n; i++)
    {
        // 看重新开始大,还是加上之前的大
        max_end_here1 = max(max_end_here1 + a[i], a[i]);
        max_so_far1 = max(max_so_far1, max_end_here1);
    }
    int min_so_far1 = a[1];
    int min_end_here1 = a[1];
    for (int i = 2; i <= n; i++)
    {
        min_end_here1 = min(min_end_here1 + a[i], a[i]);
        min_so_far1 = min(min_so_far1, min_end_here1);
    }
    return 0;
}