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
    ll m=100000;
    vector<ll> t(n), x(n), a(n);
    rep(i, n)cin>>t[i]>>x[i]>>a[i];
    t.push_back(9999999999);
    vector<vector<ll>> dp(m+1, vector<ll>(5, -1));
    ll now=0;
    dp[0][0]=0;
    rep2(1, i, m+1){
        rep(j, 5){
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
            if(j!=0)dp[i][j-1]=max(dp[i][j-1], dp[i-1][j]);
            if(j!=4)dp[i][j+1]=max(dp[i][j+1], dp[i-1][j]);
            // cout<<dp[i][j]<<" ";
        }
        if(i==t[now]){
            // coc4(i, a[now], x[now], dp[i][x[now]])
            if(dp[i][x[now]]!=-1)dp[i][x[now]]+=a[now];
            now++;
        }
        // cout<<endl;
    }
    ll mx=-1;
    rep(i, 5)mx=max(mx, dp[m][i]);
    cout<<mx<<endl;
}