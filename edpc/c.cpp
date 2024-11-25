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
    ll n;
    cin>>n;
    vector<ll> a(n), b(n), c(n);
    rep(i, n)cin>>a[i]>>b[i]>>c[i];
    vector<vector<ll>> dp(n, vector<ll>(3, 0));
    dp[0][0]=a[0], dp[0][1]=b[0], dp[0][2]=c[0];
    rep2(1, i, n){
        dp[i][0]=max(dp[i-1][1], dp[i-1][2])+a[i];
        dp[i][1]=max(dp[i-1][0], dp[i-1][2])+b[i];
        dp[i][2]=max(dp[i-1][0], dp[i-1][1])+c[i];
    }
    ll ans=0;
    rep(i, 3)ans=max(ans, dp[n-1][i]);
    cout<<ans<<endl;
}