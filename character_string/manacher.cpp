// 处理出每个位置的回文串长度
// O(n)
#include <bits/stdc++.h>
using namespace std;
const int N = 1.1e7 + 10;
int n;
// p记录每个位置的回文串长度
int p[2 * N];
char s[N];
// 新加符号后的回文串
char t[2 * N];

void manacher()
{
    n = strlen(s + 1);
    int m = 0;
    // 左右边添加符号$&,使遇到时直接失效
    t[0] = '$';
    t[++m] = '#';
    for (int i = 1; i <= n; i++)
    {
        t[++m] = s[i];
        t[++m] = '#';
    }
    t[++m] = '&';
    // 当前回文串中最大的右端点,R左边的都检查过,R右边的都没检查过
    int R = 0;
    // R对应回文串的中心点
    int M = 0;
    // i代表当前处理位置,i之前的都回文长度已知
    for (int i = 1; i <= m; i++)
    {
        // i>R则i右边的字符都没检查过
        if (i >= R)
        {
            p[i] = 1;
        }
        else
        {
            // j:2*M-i是取i关于M对称的已知点
            // j和i对称,所以j和i在R内的部分等价
            int temp1 = p[2 * M - i]; // j的回文长度
            int temp2 = R - i + 1;    // i到R的距离
            // 如果回文长度大于距离,大于距离的部分位置,从那里开始中心扩展
            // 否则从j(即也是i)的已知回文长度开始中心扩展
            p[i] = min(temp1, temp2);
        }
        // 不用检查越界,因为遇到$和&必失效
        while (t[i - p[i]] == t[i + p[i]])
        {
            p[i]++;
        }
        // 如果最新右边界大于R,更新R
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
    // 可以当结论记住,增加符号后的新s,
    // 回文串中心到两边长度-1(即p中记录的值)就是原s整个回文串长度
    printf("%d\n", ans - 1);
}
int main()
{
    scanf("%s", s + 1);
    manacher();
    return 0;
}