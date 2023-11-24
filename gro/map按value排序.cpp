// 可以less greater 重载结构体运算符
#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) // 要用常数，不然编译错误
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
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        cout << it->first << '\t' << it->second << endl;
        arr.push_back(make_pair(it->first, it->second));
    }
    sort(arr.begin(), arr.end(), cmp);
    for (vector<pair<int, int>>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        cout << it->first << '\t' << it->second << endl;
    }
    return 0;
}