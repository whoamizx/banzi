// 石子合并
/*设有N堆石子排成一排，。每堆石子有一定的质量m。现在要将这N堆石子合并成为一堆。
每次只能合并相邻的两堆，合并的代价为这两堆石子的质量之和，
试找出一种合理的方法，使总的代价最小，并输出最小代价。*/
#include <bits/stdc++.h>
using namespace std;
int n, a[501], f[501][501], s[501];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }
    memset(f, 127, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        f[i][i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            for (int k = j; k < j + i; k++)
            {
                f[j][j + i] = min(f[j][j + i], f[j][k] + f[k + 1][j + i] + s[j + i] - s[j - 1]);
            }
        }
    }
    printf("%d\n", f[1][n]);
    return 0;
}