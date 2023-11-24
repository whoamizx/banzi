// 求是几个字符串的前缀
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e6 + 10;
// 多组输入记得清0
int n, m;
int cnt = 0;
signed nxt[N][129];
int tot[N];
char str[N]; // 默认最长输入字符串长度

void insert(char s[], int len)
{
    int now = 0;
    for (int i = 1; i <= len; i++) // 1到len
    {
        int x = s[i];
        if (!nxt[now][x])
        {
            nxt[now][x] = ++cnt;
        }
        now = nxt[now][x];
        tot[now]++;
    }
}
void search(char s[], int len)
{
    int now = 0;
    bool ok = true;
    for (int i = 1; i <= len; i++) // 1到len
    {

        int x = s[i];
        if (!nxt[now][x])
        {
            ok = false;
        }
        else
            now = nxt[now][x];
    }
    if (!ok)
    {
        printf("0\n");
    }
    else
    {
        printf("%lld\n", tot[now]);
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // memset会t
        for (int i = 0; i <= cnt; i++)
        {
            tot[i] = 0;
            for (int j = 0; j <= 127; j++)
            {
                nxt[i][j] = 0;
            }
        }
        cnt = 0;
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            scanf("%s", str + 1);
            int len = strlen(str + 1); // 从1开始
            insert(str, len);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%s", str + 1);
            int len = strlen(str + 1); // 从1开始
            search(str, len);
        }
    }
    return 0;
}