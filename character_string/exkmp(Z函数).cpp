// 扩展kmp,又名Z函数
/*exKMP用于解决寻找一个串与另一个串的所有后缀的最长相同前缀*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e7 + 10;
// 记录 原串的i到n的字串 与 原串 的最长公共前缀
int z[N];
void exkmp()
{
    int L = 1, R = 0; // Z-Box的左右端点
    z[1] = 0;
    // 获取Z数组
    for (int i = 2; i <= n; i++)
    {
        // 初始化从什么长度开始扩展
        // 如果i在Z-Box外面说明不知道状态,只能暴力更新
        if (i > R)
        {
            z[i] = 0;
        }
        else
        {
            // z[i与L的距离就是]就是i现有能初始化成的长度
            // 利用之前存储的z函数
            int k = i - L + 1;
            // 如果超出Z-Box说明后面有不知道的部分需要暴力扩展
            z[i] = min(z[k], R - i + 1);
        }
        // 暴力扩展
        while (i + z[i] <= n && s[z[i] + 1] == s[i + z[i]])
        {
            z[i]++;
        }
        // 如果扩展到右端点之外
        // 更新Z-Box
        if (i + z[i] - 1 > R)
        {
            L = i;
            R = i + z[i] - 1;
        }
    }
}
signed main()
{
}