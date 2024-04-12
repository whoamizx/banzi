// 求比这个数字小的正整数有几个与他互素
#define int long long
int eular(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            // 欧拉函数公式
            ans = (ans / i) * (i - 1);
            // 去掉这个质因数
            while (n % i == 0)
                n /= i;
        }
    }
    // 说明n就是质数
    if (n > 1)
    {
        // ans=n-1;
        ans = (ans / n) * (n - 1);
    }
    return ans;
}