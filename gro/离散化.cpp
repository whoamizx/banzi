// 离散化
#include <bits/stdc++.h>
using namespace std;
const int N = 10100;
int n;
int a[N];
vector<int> num;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        num.push_back(a[i]);
    }
    sort(num.begin(), num.end());
    // 有序数组的去重
    num.erase(unique(num.begin(), num.end()), num.end());
    for (int i = 1; i <= n; i++)
    {
        int rk = lower_bound(num.begin(), num.end(), a[i]) - num.begin();
        printf("%d ", rk + 1);
    }
    return 0;
}