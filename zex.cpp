#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char a[N];
int main()
{
    map<char, int> mp;
    scanf("%s", a + 1);
    int n = strlen(a + 1);
    for (int i = 1; i <= n; i++)
    {
        mp[a[i]]++;
    }
    for (auto y : mp)
    {
        printf("%c:%d times\n", y.first, y.second);
    }
    return 0;
}