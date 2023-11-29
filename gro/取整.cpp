#include <bits/stdc++.h>
using namespace std;
#define int long long
// a/b向下取整包括a是负数的情况
int floordiv(int a, int b)
{
    if (a % b == 0)
        return a / b;
    else if (a > 0)
        return a / b;
    else
        return a / b - 1;
}
int ceildiv(int a, int b)
{
    if (a % b == 0)
        return a / b;
    else if (a > 0)
        return a / b + 1;
    else
        return a / b;
}
signed main()
{

    return 0;
}