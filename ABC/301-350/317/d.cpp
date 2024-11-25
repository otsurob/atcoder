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

ll inf=999999999999999;

int main(){
    ll n;
    cin>>n;
    vector<ll> x(n), y(n), z(n);
    rep(i, n) cin>>x[i]>>y[i]>>z[i];
    vector<ll> gt(n);
    rep(i, n){
        if(x[i]<y[i]) gt[i]=z[i]*2;
        else gt[i]=z[i];
    }
    vector<ll> c(n, 0);
    ll goal=0;
    rep(i, n){
        if(x[i]<y[i]){
            c[i]=(y[i]-x[i]+1)/2;
            goal+=z[i];
        }
    }
    ll zs=0;
    rep(i, n) zs+=z[i];
    vector<vector<ll>> dp(n, vector<ll>(2*zs+1, inf));
    dp[0][0]=0;
    dp[0][gt[0]]=c[0];
    // coc3(zs, gt[0], dp[0][gt[0]]);
    // coc(c[n-1])
    rep(i, n-1){
        rep(j, 2*zs+1){
            if(dp[i][j]==inf) continue;
            dp[i+1][j]=min(dp[i+1][j], dp[i][j]);
            dp[i+1][j+gt[i+1]]=min(dp[i+1][j+gt[i+1]], dp[i][j]+c[i+1]);
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    ll mn=inf;
    rep2(goal, i, 2*zs+1) mn=min(mn, dp[n-1][i]);
    // rep2(goal, i, 2*zs+1) cout<<dp[n-1][i]<<" ";
    cout<<mn<<endl;
}