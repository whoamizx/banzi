#include <bits/stdc++.h>
using namespace std;
#define int long long
// 对于一个长度为N的整数数列 A1,A2··AN，小蓝想知道下标l到r的部分和
// 然而，小蓝并不知道数列中每个数的值是多少，他只知道它的 M个部分和的值。
// 其中第i个部分和是下标li到ri的部分和
// 第一行包含 3 个整数N、M和Q。分别代表数组长度、已知的部分和数量 和询问的部分和数量
// 接下来 M 行，每行包含3个整数li,ri,Si。
// 接下来Q行，每行包含2个整数l和r，代表一个小蓝想知道的部分和
const int N = 1e5 + 10;
int fa[N];
int val[N];
int find(int x)
{
    if (x == fa[x])
    {
        return x;
    }
    // 带权并查集路径压缩
    // 先把现在父亲存起来
    int t = fa[x];
    // 更新父亲权值
    // 但是父亲变成根了
    fa[x] = find(fa[x]);
    // 加上之前存的现在父亲的权值
    val[x] += val[t];
    return fa[x];
}
signed main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= N - 5; i++)
    {
        fa[i] = i;
    }
    while (m--)
    {
        int l, r, s;
        scanf("%lld%lld%lld", &l, &r, &s);
        // sum[r]-sum[l-1]=s
        l--;
        int fx = find(l);
        int fy = find(r);
        if (fx != fy)
        {
            // 路径压缩,权值更新
            val[fx] = -val[l] + s + val[r];
            fa[fx] = fy;
        }
    }
    while (q--)
    {
        int l, r;
        scanf("%lld%lld", &l, &r);
        l--;
        int fx = find(l);
        int fy = find(r);
        if (fx != fy)
        {
            printf("UNKNOWN\n");
        }
        else
        {
            // 可能有负数,不能abs
            printf("%lld\n", val[l] - val[r]);
        }
    }
    return 0;
}