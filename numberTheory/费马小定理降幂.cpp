#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
#define int long long
const int mod=998244353;
int fastpow(int a,int n)
{
	int ans=1;
	a%=mod;
	while(n){if(n&1){ans*=a;ans%=mod;}a*=a;a%=mod;n>>=1;}
	return ans;
}
void solve()
{
	int n;
    //n是1e18
	cin>>n;
	int tempn=n;
	int cnt=0;
	while(tempn)
	{
		tempn/=10;
		cnt++;
	}
	int ans=1;
	ans*=n;
	ans%=mod;
	n%=(mod-1);
    //n*cnt会爆longlong,但是可以给指数mod上mod-1来降幂
	ans*=(fastpow(10,n*cnt)-1);
	ans%=mod;
	ans*=fastpow(fastpow(10,cnt)-1,mod-2);
	ans%=mod;
	printf("%lld\n",ans);
}
signed main()
{
	int T;
	// cin >> T;
	T=1;
	while (T--)
	{
		solve();
	}
	return 0;
}
