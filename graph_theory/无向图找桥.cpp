//无向图找桥
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10;
vector<int>edge[N];
int dfn[N];
int low[N];//不经过从父亲过来的边,能到的最小dfn序
int id=0;
vector<pair<int,int>>ans;
void dfs(int now,int fa)
{
    dfn[now]=low[now]=++id;
    for(auto y:edge[now])
    {
        //是父亲
        if(y==fa)
        {
            continue;
        }
        //访问过
        if(dfn[y])
        {
            low[now]=min(low[now],dfn[y]);
        }
        else//没访问过
        {
            dfs(y,now);
            low[now]=min(low[now],low[y]);
            if(low[y]>dfn[now])
            {
                if(now>y)
                {
                    swap(now,y);
                }
                ans.push_back({now,y});
            }
        }
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%lld%lld",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1,-1);
    sort(ans.begin(),ans.end());
    for(auto y:ans)
    {
        printf("%lld %lld\n",y.first,y.second);
    }
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