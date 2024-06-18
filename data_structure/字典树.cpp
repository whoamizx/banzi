// 字符串是否出现过
#include <bits/stdc++.h>
using namespace std;
// 字符串总长度最大值
const int N = 1e5 + 10;
// 多组输入记得清零
int cnt = 0;
int nxt[N][27]; // 默认小写字母//静态
bool isend[N];  
void insert(char s[], int len)
{
    int now = 0;
    for (int i = 1; i <= len; i++) // 1到len
    {
        int x = s[i] - 'a'; // 默认小写字母
        if (!nxt[now][x])
        {
            nxt[now][x] = ++cnt;
        }
        now = nxt[now][x];
    }
    isend[now] = 1;
}
bool search(char s[], int len)
{
    int now = 0;
    for (int i = 1; i <= len; i++) // 1到len
    {
        int x = s[i] - 'a'; // 默认小写字母
        if (!nxt[now][x])
        {
            return false;
        }
        else
            now = nxt[now][x];
    }
    return isend[now];
}
int main()
{
    int n, m;
    cin >> n >> m;
    char str[101]; // 默认最长输入字符串长度100且全为小写字母
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
        if (search(str, len))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    return 0;
}