#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e4+10;
vector<int>edge[N];
int id=0;
int dfn[N];
int low[N];
int ans[N];
int root;
int cnt=0;
void dfs(int now,int fa)
{
    dfn[now]=low[now]=++id;
    int son=0;
    for(auto y:edge[now])
    {
        // 
        // if(y==fa)
        // {
        //     continue;
        // }
        if(dfn[y])
        {
            low[now]=min(low[now],dfn[y]);
        }
        else
        {
            son++;
            dfs(y,now);
            low[now]=min(low[now],low[y]);
            if(low[y]>=dfn[now]&&now!=root)//根要特判//注意这里时>=
            {
                cnt+=!ans[now];
                ans[now]=1;
            }
        }
    }
    //根的特判
    if(son>=2&&root==now)
    {
        cnt+=!ans[now];
        ans[now]=1;
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            root=i;
            dfs(i,-1);
        }
    }
    printf("%lld\n",cnt);
    for(int i=1;i<=n;i++)
    {
        if(ans[i])
        {
            printf("%lld ",i);
        }
    }
    printf("\n");
}
signed main()
{
    int T;
    // cin>>T;
    T=1;
    while(T--)
    {
        solve();
    }
    return 0;
}