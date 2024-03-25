// 可以less greater 重载结构体运算符
#include <bits/stdc++.h>
using namespace std;
// 要用常数，不然编译错误
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.second < p2.second;
}
int main(void)
{
    map<int, int> mp;
    mp[1] = 4;
    mp[2] = 3;
    mp[3] = 2;
    mp[4] = 1;
    vector<pair<int, int>> arr;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        cout << it->first << '\t' << it->second << endl;
        arr.push_back({it->first, it->second});
    }
    sort(arr.begin(), arr.end(), cmp);
    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        cout << it->first << '\t' << it->second << endl;
    }
    return 0;
}