#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
vector<int> edge[N + 1];
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  return 0;
}
