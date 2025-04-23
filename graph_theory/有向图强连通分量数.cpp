//有向图大于2的强连通分量的数目
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e4+10;
vector<int>edge[N];
int dfn[N];
int low[N];
int id=0;
int ans=0;
stack<int>stk;
int cnt=0;//强连通分量数目
int num[N];//每个强联通分量的大小
int vis[N];//是否在栈里面
void dfs(int now)
{
    dfn[now]=low[now]=++id;
    stk.push(now);
    vis[now]=true;
    for(auto y:edge[now])
    {
        if(!dfn[y])
        {
            dfs(y);
            low[now]=min(low[now],low[y]);
        }
        else if(vis[y])//这里是vis不是dfn
        {
            low[now]=min(low[now],dfn[y]);
        }
    }
    if(low[now]==dfn[now])
    {
        cnt++;
        while(stk.top()!=now)
        {
            num[cnt]++;
            vis[stk.top()]=0;
            stk.pop();
        }
        num[cnt]++;
        vis[stk.top()]=0;
        stk.pop();
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
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            dfs(i);
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        if(num[i]>=2)
        {
            ans++;
        }
    }
    printf("%lld\n",ans);
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