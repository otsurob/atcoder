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
    ll mod=998244353;
    vector<ll> a(n);
    cinv(a, n);
    vector<vector<vector<vector<ll>>>> dp;
    dp.resize(n+1);
    rep(i, n+1)dp[i].resize(n+1);
    rep(i, n+1)rep(j, n+1)dp[i][j].resize(n+1);
    rep(i, n+1)rep(j, n+1)rep(k, n+1)dp[i][j][k].resize(n+1, 0);
    dp[0][0][0][0]=0;
    rep2(1, i, n+1){
        rep2(1, j, n+1){
            dp[i][j-1][0][0]=1;
            rep2(1, k, j+1){
                rep(l, n+1){
                    dp[i][j][k][l] += dp[i][j-1][k][l];
                    dp[i][j][k][l] %= mod;
                    dp[i][j][k][(l+a[j-1])%i] += dp[i][j-1][k-1][l];
                    dp[i][j][k][(l+a[j-1])%i]%=mod;
                }
            }
        }
    }

    // rep2(1, i, n+1){
    //     cout<<"i="<<i<<endl;
    //     rep2(1, j, n+1){
    //         cout<<"j="<<j<<endl;
    //         rep2(1, k, n+1){
    //             rep(l, n+1){
    //                 cout<<dp[i][j][k][l]<<" ";
    //             }
    //             codl();
    //         }
    //         codl();
    //     }
    //     codl();
    // }
    ll ans=0;
    rep2(1, k, n+1)ans= (ans+dp[k][n][k][0])%mod;
    cout<<ans<<endl;
}