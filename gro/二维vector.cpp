#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<char>> vc;
signed main()
{
    int n, m;
    cin >> n >> m;
    for (auto &row : vc)
    {
        row.resize(m + 1, '@');
    }
    vc.resize(n + 1, vector<char>(m + 1, '@'));
    return 0;
}
