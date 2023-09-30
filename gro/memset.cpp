#include <bits/stdc++.h>
using namespace std;
int a[10];
long long b[10];
double c[10];
int main()
{
    // int
    memset(a, 127, sizeof(a)); // 较大,2139062143
    memset(a, -1, sizeof(a));  //-1；
    memset(a, 128, sizeof(a)); // 较小,-2139062144

    // long long
    memset(b, 0x7f, sizeof(b)); // 极大
    memset(b, 0x3f, sizeof(b)); // 较大
    memset(a, -1, sizeof(b));   //-1；
    memset(a, 0xc0, sizeof(b)); // 较小
    memset(a, 0x80, sizeof(b)); // 极小
    // double同int
    return 0;
}