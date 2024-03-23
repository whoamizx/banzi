#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int a[N];
int L[N];
int R[N];
int n, k;
struct BIT
{
    int c[N];
    void modify(int x, int s)
    {
        for (; x <= n; x += x & -x)
        {
            c[x] = max(s, c[x]); //
        }
    }
    int query(int x)
    {
        int s = 0;
        for (; x; x -= x & -x)
        {
            s = max(s, c[x]); //
        }
        return s;
    }

} le, re, s;
signed main()
{
    cin >> n >> k;
    vector<int> vc;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        vc.push_back(a[i]);
    }
    a[0] = 1;
    a[n + 1] = n + 1;
    // 离散化
    sort(vc.begin(), vc.end());
    vc.erase(unique(vc.begin(), vc.end()), vc.end());
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(vc.begin(), vc.end(), a[i]) - vc.begin() + 1;
    }
    for (int i = 1; i <= n; i++) // 正向LIS
    {
        L[i] = le.query(a[i]) + 1;
        le.modify(a[i], L[i]);
    }
    for (int i = n; i; i--) // 反向LIS
    {
        R[i] = re.query(n - a[i] + 1) + 1;
        re.modify(n - a[i] + 1, R[i]);
    }
    int ans = 0;
    for (int i = k + 1; i <= n + 1; i++)
    {
        s.modify(a[i - k - 1], L[i - k - 1]);
        ans = max(ans, s.query(a[i]) + k + R[i]);
    }
    printf("%lld\n", ans);
    return 0;
}