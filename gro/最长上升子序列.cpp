#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int a[N];
int s[N];
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    int tot = 0;
    s[++tot] = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > s[tot]) // 如果是>=底下要给成upper_bound
        {
            s[++tot] = a[i];
        }
        else
        {
            int id = lower_bound(s + 1, s + 1 + tot, a[i]) - s;
            s[id] = a[i];
        }
    }
    printf("%lld\n", tot);
    return 0;
}