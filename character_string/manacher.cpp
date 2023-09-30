// Manacher
// 求最长回文子串
// O(n)
#include <bits/stdc++.h>
using namespace std;
const int N = 1.1e7 + 10;
int n;
int p[2 * N];
//p记录每个位置的回文串长度
char s[N];
char t[2 * N];

void manacher()
{
    n = strlen(s + 1);
    int m = 0;
    t[++m] = '$';
    for (int i = 1; i <= n; i++)
    {
        t[++m] = s[i];
        t[++m] = '$';
    }
    int M = 0, R = 0;
    for (int i = 1; i <= m; i++)
    {
        if (i > R)
        {
            p[i] = 1;
        }
        else
        {
            p[i] = min(p[2 * M - i], R - i + 1); // 合并两种情况//k-p[k]+1与L的大小
        }
        while (i - p[i] > 0 && i + p[i] <= m && t[i - p[i]] == t[i + p[i]])
        {
            ++p[i];
        }
        if (i + p[i] - 1 > R)
        {
            M = i;
            R = i + p[i] - 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = max(ans, p[i]);
    }
    printf("%d\n", ans - 1); // 去掉符号$
}
int main()
{
    scanf("%s", s + 1);
    manacher();
    return 0;
}