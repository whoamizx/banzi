// 汉密尔顿回路
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> edge[20010];
bool b[20010];
inline bool dfs(int x, int c)
{
  if (c == n && x == k)
  {
    return true;
  }
  for (auto y : edge[x])
  {
    if (!b[y])
    {
      b[y] = true;
      if (dfs(y, c + 1)) // return一次true后就会一直return ture因为if一直成立
      {
        return true;
      }
      b[y] = false;
    }
  }
  return false;
}
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
  scanf("%d", &k);
  if (dfs(k, 0))
  {
    printf("Yes\n");
  }
  else
  {
    printf("No\n");
  }
  return 0;
}