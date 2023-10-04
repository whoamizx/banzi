#include <bits/stdc++.h>
using namespace std;
#define int long long
// 每个魔法宝石的大小为1单元。
// 每个魔法宝石可以被分解为m个普通宝石，每个普通宝石的大小也是1单元。
// 使得最后的宝石能够占满n单元大小的空间。请问有多少种不同的分解方案
// 请输出答案模10+7。
// 如果两方案选择的魔法宝石数量不同，或分解魔法宝石在序列中的位置不同就是不同方案
const int mod = 1e9 + 7;
const int N = 200;
struct matrix
{
    int m[N][N];
};
matrix operator*(const matrix &a, const matrix &b)
{
    matrix c;
    memset(c.m, 0, sizeof(c.m));
    for (int i = 0; i < N; i++) // N太大了这里会爆//不会了,因为0的时候跳过了
    {
        for (int k = 0; k < N; k++)
        {
            if (a.m[i][k])
                for (int j = 0; j < N; j++)
                {
                    if (b.m[k][j])
                        c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
                }
        }
    }
    return c;
}
matrix pow_matrix(matrix a, int n)
{
    matrix ans;
    memset(ans.m, 0, sizeof(ans.m)); // memset太大的N也会TLE
    for (int i = 0; i < N; i++)
    {
        // 初始化位单位矩阵,相当于普通快速幂的ans=1
        ans.m[i][i] = 1;
    }
    while (n)
    {
        if (n & 1)
        {
            ans = ans * a;
        }
        a = a * a;
        n >>= 1;
    }
    return ans;
}
signed main()
{
    long long n;
    int m;
    cin >> n >> m;
    // 递推公式f[i]=f[i-1]+f[i-m]
    matrix de;
    memset(de.m, 0, sizeof(de.m));
    for (int i = 2; i <= m; i++)
    {
        de.m[i][i - 1] = 1;
    }
    de.m[1][m] = 1;
    de.m[m][m] = 1;
    // ans.m[i]就代表在i个宝石时有多少种方案
    matrix ans;
    memset(ans.m, 0, sizeof(ans.m));//初始令第m位为0个宝石
    ans.m[1][m] = 1;
    ans = ans * pow_matrix(de, n);
    printf("%lld\n", ans.m[1][m]);//
    return 0;
}