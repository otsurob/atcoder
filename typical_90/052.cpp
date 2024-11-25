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
    vector<vector<ll>> a(n, vector<ll>(6));
    rep(i, n)rep(j, 6)cin>>a[i][j];
    vector<vector<ll>> dp(n, vector<ll>(6, 0));
    dp[0]=a[0];
    ll mod=1000000007;
    rep2(1, i, n){
        rep(j, 6){
            rep(k, 6){
                dp[i][j]+=(dp[i-1][k]*a[i][j])%mod;
                dp[i][j]%=mod;
            }
        }
    }
    ll ans=0;
    rep(i, 6)ans=(ans+dp[n-1][i])%mod;
    cout<<ans<<endl;
}