// Kmp
// O(m+n)
/*字符串匹配问题,找出s中所有的p串*/
// 首先输出若干行，每行一个整数，按从小到大的顺序输出p在s中出现的位置。
// 最后一行输出next数组
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m;

int nxt[N];
int f[N + 1];
char s[N], p[N];
void kmp()
{
    n = strlen(s + 1);
    m = strlen(p + 1);
    // 前缀已经匹配的长度
    int j = 0;
    nxt[1] = 0; // 1必定是0,因为next数组不能等于字符串长度
    // 求next数组
    for (int i = 2; i <= m; i++)
    {
        // 前缀下一个匹配位置,与后缀下一个不相等,
        // 利用之前已经更新的next数组,前缀一直跳到与后缀下一个相等,或者跳到0为止
        while (j > 0 && p[j + 1] != p[i])
        {
            j = nxt[j];
        }
        // 前缀下一个匹配位置,与后缀下一个相等,直接j++
        if (p[j + 1] == p[i])
        {
            j++;
        }
        nxt[i] = j;
    }
    // 这里代表已经匹配的长度
    j = 0;
    for (int i = 1; i <= n; i++)
    {
        // p串匹配完了或者失配了并且j>0(即还能跳,没有跳到头)跳到上一个匹配状态即next数组
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

    scanf("%s %s", s + 1, p + 1);
    kmp();

    for (int i = 1; i <= n; i++)
    {
        //
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