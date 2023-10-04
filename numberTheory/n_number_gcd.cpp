//n个数的最大公约数
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, n;
    cin >> n;
    cin >> a;
    for (int i = 2; i <= n; i++)
    {
        cin >> b;
        if (a < b)
            swap(a, b);
        while (b)
        {
            int r = a % b;
            a = b;
            b = r;
        }
    }
    cout << a << endl;
    return 0;
}
