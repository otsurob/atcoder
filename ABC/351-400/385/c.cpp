#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<' ';
#define codl() cout<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
#define decout(a) cout<<fixed<<setprecision(15)<<a<<endl;
#define wow() cout<<"wow"<<endl;
#define coc(a) cout<<a<<endl;;
#define coc2(a, b) cout<<a<<" "<<b<<endl;
#define coc3(a, b, c) cout<<a<<" "<<b<<" "<<c<<endl;
#define coc4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define pll pair<ll, ll>
#define fst first
#define snd second
#define inf 999999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll n;
    cin>>n;
    vector<ll> h(n);
    cinv(h, n);
    vector<vector<ll>> dp(n+1, vector<ll>(n, 1));
    // rep2(1, i, n+1)dp[1][i]=1;
    // rep2(1, i, n)dp[i][0]=1;
    rep2(1, i, n){
        rep(j, n){
            if(dp[i][j]==0)continue;
            if(j+i>=n)continue;
            if(h[j]==h[j+i])dp[i][j+i]=dp[i][j]+1;
        }
    }
    ll mx=-1;
    rep(i, n+1)rep(j, n)chmax(mx, dp[i][j]);
    // rep(i, n+1){
    //     rep(j, n){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     codl();
    // }
    cout<<mx<<endl;
}