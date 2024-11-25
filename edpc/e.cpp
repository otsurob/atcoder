#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
#define wow() cout<<"wow"<<endl;
#define coc(a) cout<<a<<endl;;
#define coc2(a, b) cout<<a<<" "<<b<<endl;
#define coc3(a, b, c) cout<<a<<" "<<b<<" "<<c<<endl;
#define coc4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define pll pair<ll, ll>
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

int main(){
    ll n, w;
    cin>>n>>w;
    vector<ll> a(n), b(n);
    rep(i, n)cin>>a[i]>>b[i];
    ll inf=999999999999999;
    vector<vector<ll>> dp(n+1, vector<ll>(100002, inf));
    dp[0][0]=0;
    rep2(1, i, n+1){
        dp[i][0]=0;
        rep(j, 100002){
            if(dp[i-1][j]!=inf){
                dp[i][j]=min(dp[i][j], dp[i-1][j]);
                dp[i][j+b[i-1]]=min(dp[i][j+b[i-1]], dp[i-1][j]+a[i-1]);
                // coc2(j+b[i-1], dp[i][j+b[i-1]])
            }
        }
    }
    ll ans=-1;
    rep(i, 100002)if(dp[n][i]<=w)ans=max(ans, i);
    cout<<ans<<endl;
}