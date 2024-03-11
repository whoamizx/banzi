#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int a[N];
int b[N];
int suma[N];
int sumb[N];
signed main()
{
    int n, m;
    cin >> n >> m;
    int maxa = -1e4 - 10;
    int mina = 1e4 + 10;
    int maxb = -1e4 + 10;
    int minb = 1e4 + 10;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        maxa = max(a[i], maxa);
        mina = min(a[i], mina);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &b[i]);
        maxb = max(b[i], maxb);
        minb = min(b[i], minb);
    }
    int max_so_far1 = a[1];
    int max_end_here1 = a[1];
    for (int i = 2; i <= n; i++)
    {
        max_end_here1 = max(max_end_here1 + a[i], a[i]);
        max_so_far1 = max(max_so_far1, max_end_here1);
    }
    int max_so_far2 = b[1];
    int max_end_here2 = b[1];
    for (int i = 2; i <= m; i++)
    {
        max_end_here2 = max(max_end_here2 + b[i], b[i]);
        max_so_far2 = max(max_so_far2, max_end_here2);
    }
    int min_so_far1 = a[1];
    int min_end_here1 = a[1];
    for (int i = 2; i <= n; i++)
    {
        min_end_here1 = min(min_end_here1 + a[i], a[i]);
        min_so_far1 = min(min_so_far1, min_end_here1);
    }
    int min_so_far2 = b[1];
    int min_end_here2 = b[1];
    for (int i = 2; i <= m; i++)
    {
        min_end_here2 = min(min_end_here2 + b[i], b[i]);
        min_so_far2 = min(min_so_far2, min_end_here2);
    }
    printf("%lld\n", max({mina * minb, mina * maxb, maxa * minb, maxa * maxb, max_so_far1 * max_so_far2, min_so_far1 * min_so_far2}));
    return 0;
}