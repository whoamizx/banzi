#include<bits/stdc++.h>
#define int long long
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
char a[100]={'L','R','U','L'};
signed main(){
    int T=10; cout<<T<<"\n";
    for(int i=1;i<=T;i++){
        int n=(rnd()%10)+1;
        cout<<n<<" ";
        int k=(rnd()%10)+1;
        cout<<k<<endl;
        for(int j=1;j<=n;j++)
        {
            cout<<a[rnd()%4];
        }
        cout<<endl;
    }
    return 0;
}