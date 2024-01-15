// 最长上升子序列
// O(nlogn)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int N = 1e5 + 10;
struct Node
{
    int id;
    int val;
} node[N];
int s[N];
int main()
{
    int n;
    int tot = 0;
    int tmp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &node[i].val);
        node[i].id = i;
    }
    s[++tot] = node[1].val;
    for (int i = 2; i <= n; i++)
    {
        if (node[i].val > s[tot])
        {
            s[++tot] = node[i].val;
        }
        else
        {
            tmp = lower_bound(s + 1, s + tot + 1, a[i]) - s;
            s[tmp] = node[i].val;
        }
    }
    return 0;
}
