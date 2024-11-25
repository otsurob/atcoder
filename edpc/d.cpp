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
    vector<vector<ll>> dp(n+1, vector<ll>(w+1, -1));
    dp[0][0]=0;
    rep2(1, i, n+1){
        dp[i][0]=0;
        rep(j, w+1){
            if(dp[i-1][j]!=-1){
                dp[i][j]=max(dp[i][j], dp[i-1][j]);
                if(j+a[i-1]<=w)dp[i][j+a[i-1]]=max(dp[i][j+a[i-1]], dp[i-1][j]+b[i-1]);
            }
        }
    }
    // rep(i, n+1){
    //     rep(j, w+1)cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    ll ans=0;
    rep(i, w+1)ans=max(ans, dp[n][i]);
    cout<<ans<<endl;
}