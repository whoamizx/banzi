#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1.1e7 + 10;
int n;
char a[N];
char s[N * 2];
int b1 = 1313, b2 = 13131, p1 = 100000007, p2 = 999999751;
long long c1[N * 2], c2[N * 2], h1[2 * N], h2[N * 2], H1[2 * N], H2[N * 2];
// 求一段的hash
pair<int, int> calc1(int l, int r)
{
    return {(h1[r] - h1[l - 1] * c1[r - l + 1] % p1 + p1) % p1,
            (h2[r] - h2[l - 1] * c2[r - l + 1] % p2 + p2) % p2};
}
// 反转的l和r不同
pair<int, int> calc2(int l, int r)
{
    return {(H1[l] - H1[r + 1] * c1[r - l + 1] % p1 + p1) % p1,
            (H2[l] - H2[r + 1] * c2[r - l + 1] % p2 + p2) % p2};
}
signed main()
{
    s[0] = '#';
    scanf(" %s", a + 1);
    n = strlen(a + 1);
    // printf("n:%d\n", n);
    int m = 0;
    s[++m] = '$';
    for (int i = 1; i <= n; i++)
    {
        s[++m] = a[i];
        s[++m] = '$';
    }
    c1[0] = 1;
    c2[0] = 1;
    // 存次方
    for (int i = 1; i <= m; i++)
    {
        c1[i] = c1[i - 1] * b1 % p1;
        c2[i] = c2[i - 1] * b2 % p2;
    }
    // 双哈希
    // 前后各做一次
    for (int i = 1; i <= m; i++)
    {
        h1[i] = (h1[i - 1] * b1 % p1 + s[i]) % p1;
        h2[i] = (h2[i - 1] * b2 % p2 + s[i]) % p2;
    }
    // i+1,应该与前一个比较
    for (int i = m; i; i--)
    {
        H1[i] = (H1[i + 1] * b1 % p1 + s[i]) % p1;
        H2[i] = (H2[i + 1] * b2 % p2 + s[i]) % p2;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int L = 0, R = m + 1;
        while (L + 1 < R)
        {
            int M = (L + R) / 2;
            if (calc1(i, i + M - 1) == calc2(i - M + 1, i) && i - M + 1 > 0)
            {
                L = M;
            }
            else
            {
                R = M;
            }
        }
        ans = max(ans, L);
    }
    // 去掉符号后长度,就是扩展长度-1
    printf("%d\n", ans - 1);
    return 0;
}
