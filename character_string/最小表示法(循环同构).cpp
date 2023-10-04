//找到数组中字典序最小的循环同构
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int a[2 * N];
int n;
int getmin()
{
    for (int i = 1; i <= n; i++)
    {
        a[i + n] = a[i];
    }
    int i = 1, j = 2;
    while (j <= n)
    {
        int k = 0;
        while (k < n && a[i + k] == a[j + k])
        {
            k++;
        }
        if (a[i + k] > a[j + k])
        {
            i += k + 1;
        }
        else
        {
            j += k + 1;
        }
        if (i == j)
        {
            j++;
        }
        if (i > j)
        {
            swap(i, j);
        }
    }
    return i;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int temp = getmin();
    for (int i = temp; i < temp + n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}