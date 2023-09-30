/*输入一个 n 行 n 列的整数矩阵，
再输入 m 个操作，每个操作包含五个整数 x1，y1，x2，y2，c，
其中 (x1, y1) 和 (x2, y2) 表示一个子矩阵的左上角坐标和右下角坐标。
每个操作都要将选中的子矩阵中的每个元素的值加上 c。
请你将进行完所有操作后的矩阵输出。*/
// 此处c一直等于1
//  二维差分
// 当n(1e9 )过大时,需要离散化//每块是一样的
#include <bits/stdc++.h>
using namespace std;
long long sum[1010][1010];
int a[1010][1010];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        a[x1][y1] += 1;
        a[x1][y2 + 1] -= 1;
        a[x2 + 1][y1] -= 1;
        a[x2 + 1][y2 + 1] += 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
            printf("%lld ", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}