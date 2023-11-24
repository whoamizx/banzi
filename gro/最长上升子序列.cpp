// 最长上升子序列
// O(nlogn)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int s[N];
int main()
{
    int n;
    int tot = 0;
    int tmp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    s[++tot] = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > s[tot])
        {
            s[++tot] = a[i];
        }
        else
        {
            tmp = lower_bound(s + 1, s + tot + 1, a[i]) - s;
            s[tmp] = a[i];
        }
    }
    printf("%d\n", tot);
    return 0;
}
