/*八皇后问题*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100], b[100], c[100], d[100];
int ans = 0;
int n;
inline void print()
{
    if (ans <= 2)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    ans++;
}
inline void dfs(int t)
{
    if (t > n)
    {
        print();
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!b[i] && !c[t + i - 1] && !d[t - i + n])
        {
            a[t] = i;
            b[i] = 1;
            c[t + i - 1] = 1;
            d[t - i + n] = 1;
            dfs(t + 1);
            b[i] = 0;
            c[t + i - 1] = 0;
            d[t - i + n] = 0;
        }
    }
    return;
}
signed main()
{

    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}