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
    ll mod=998244353;
    ll n;
    cin>>n;
    vector<ll> a(n);
    cinv(a, n);
    // map<ll, ll> dp;
    vector<vector<map<ll, ll>>> dp(n, vector<map<ll, ll>>(n+1));
    rep(i, n-1){
        rep2(i+1, j, n){
            dp[j][2][a[j]-a[i]]+=1;
        }
    }
    rep2(3, k, n+1){
    // rep(i, n){
        // rep2(3, k, n+1){
        rep(i, n){
            if(i==n-1)continue;
            rep2(i+1, j, n){
                dp[j][k][a[j]-a[i]] += dp[i][k-1][a[j]-a[i]];
                dp[j][k][a[j]-a[i]]%=mod;
            }
        }
    }
    rep(k, n){
        ll ans=0;
        if(k==0)ans=n;
        rep(j, n){
            for(auto x : dp[j][k+1]){
                ans+=x.snd;
                ans%=mod;
            }
        }
        cout<<ans%mod<<" ";
    }
    cout<<endl;
}