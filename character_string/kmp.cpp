// Kmp
// O(m+n)
/*字符串匹配问题,找出s中所有的p串*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m;
int nxt[N], f[N + 1];
char s[N], p[N];
void kmp()
{
    n = strlen(s + 1);
    m = strlen(p + 1);
    int j = 0;
    nxt[1] = 0;
    for (int i = 2; i <= m; i++)
    {
        while (j > 0 && p[j + 1] != p[i])
        {
            j = nxt[j];
        }
        if (p[j + 1] == p[i])
        {
            j++;
        }
        nxt[i] = j;
    }
    j = 0;
    for (int i = 1; i <= n; i++)
    {
        while (j == m || (j > 0 && s[i] != p[j + 1]))
        {
            j = nxt[j];
        }
        if (s[i] == p[j + 1])
        {
            j++;
        }
        f[i] = j;
    }
}
int ans[N];
int main()
{
    int cnt = 0;

    scanf("%s %s", s + 1, p + 1);
    kmp();
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == m)
        {
            printf("%d\n", i - m + 1);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d ", nxt[i]);
    }    
    return 0;
}