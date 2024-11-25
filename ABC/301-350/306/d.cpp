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
    vector<ll> x(n), y(n);
    rep(i, n) cin>>x[i]>>y[i];
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    if(x[0]==0) dp[0][0]=max(dp[0][0], y[0]);    
    else dp[0][1]=max(dp[0][1], y[0]);
    // coc2(dp[0][0], dp[0][1])
    rep2(1, i, n){
        if(x[i]==0){
            ll tmp=max(dp[i-1][0]+y[i], dp[i-1][1]+y[i]);
            dp[i][0]=max(dp[i][0], dp[i-1][0]);
            dp[i][0]=max(dp[i][0], tmp);
            dp[i][1]=dp[i-1][1];
        }
        else{
            dp[i][0]=dp[i-1][0];
            dp[i][1]=max(dp[i-1][1], dp[i-1][0]+y[i]);
        }
        // coc2(dp[i][0], dp[i][1])
    }
    cout<<max(dp[n-1][0], dp[n-1][1])<<endl;
}