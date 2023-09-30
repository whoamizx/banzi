// 最长公共子序列(离散化后的)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int N = 1e5 + 10;
int s[N];
int a[N];
int b[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        b[x] = i;
    }
    int tot = 0;
    int tmp;
    s[++tot] = b[a[1]];
    for (int i = 2; i <= n; i++)
    {
        if (b[a[i]] > s[tot])
        {
            s[++tot] = b[a[i]];
        }
        else
        {
            tmp = lower_bound(s + 1, s + tot + 1, b[a[i]]) - s;
            s[tmp] = b[a[i]];
        }
    }
    printf("%d\n", tot);
    return 0;
}
