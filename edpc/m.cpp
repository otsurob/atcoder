#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll mod=1000000007;
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    cinv(a, n);
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
    rep(i, a[0]+1)dp[1][i]=1;
    vector<vector<ll>> s(n+1, vector<ll>(k+2, 0));
    rep2(1, i, k+2)s[1][i]=(s[1][i-1]+dp[1][i-1])%mod;
    rep2(2, i, n+1){
        rep2(0, j, k+1){
            dp[i][j]=(mod+s[i-1][j+1]-s[i-1][max(0ll, j-a[i-1])])%mod;
        }
        rep2(1, j, k+2){
            s[i][j]=(s[i][j-1]+dp[i][j-1])%mod;
        }
    }
    // rep(i, n+1){
    //     rep(j, k+1){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // rep(i, n+1){
    //     rep(j, k+2){
    //         cout<<s[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][k]<<endl;
}