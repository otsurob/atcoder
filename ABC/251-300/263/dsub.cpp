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
    ll n, l, r;
    cin>>n>>l>>r;
    vector<ll> a(n);
    cinv(a, n);
    ll MAX_NUM = 99999999999999999;
    vector<vector<ll>> dp(n+1, vector<ll>(3, MAX_NUM));
    rep(i, 3)dp[0][i]=0;
    rep(i, n){
        dp[i+1][0]=min(dp[i+1][0], dp[i][0]+l);
        dp[i+1][1]=min(dp[i+1][1], dp[i][0]+a[i]);
        dp[i+1][1]=min(dp[i+1][1], dp[i][1]+a[i]);
        dp[i+1][2]=min(dp[i+1][2], dp[i][0]+r);
        dp[i+1][2]=min(dp[i+1][2], dp[i][1]+r);
        dp[i+1][2]=min(dp[i+1][2], dp[i][2]+r);
    }
    ll mx=MAX_NUM;
    rep(i, 3)mx=min(mx, dp[n][i]);
    cout<<mx<<endl;
}