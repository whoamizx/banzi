#include <bits/stdc++.h>
using namespace std;
// 给出一个整数 q，要求输出这个数字在序列中第一次出现的编号，如果没有找到的话输出−1
const int N = 1e6 + 10;
int a[N] = {0};
int n, m;
// l和r中间是分界线
int calc(int x)
{
    int L = 0, R = n + 1;
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        if (a[M] <= x) // 分界线两边含义这里决定,此时是昨天是小于等于的,右边是大于的
        {
            L = M;
        }
        else
        {
            R = M;
        }
    }
    return L;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int temp;
        scanf("%d", &temp);
        int l = calc(temp - 1) + 1;
        if (a[l] != temp)
        {
            printf("-1 ");
        }
        else
        {
            printf("%d ", l);
        }
    }
    return 0;
}