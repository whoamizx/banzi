#include <bits/stdc++.h>
using namespace std;
#define int long long
struct cmp // 自定义比较规则
{
    bool operator()(const string &str1, const string &str2)
    {
        return str1.length() < str2.length();
    }
};
bool cmp2(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.second < p2.second;
}
signed main()
{
    // 按key
    map<int, int, greater<int>> mpp;
    map<string, int, cmp> mp2;

    // 想办法按value
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
    sort(arr.begin(), arr.end(), cmp2);
    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        cout << it->first << '\t' << it->second << endl;
    }
    return 0;
}
