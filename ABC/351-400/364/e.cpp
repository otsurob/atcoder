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
    ll n, x, y;
    cin>>n>>x>>y;
    vector<ll> a(n), b(n);
    rep(i, n)cin>>a[i]>>b[i];
    ll ta=0, tb=0;
    rep(i, n)ta+=a[i], tb+=b[i];
    ll inf=99999999999999999;
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(x+2, inf)));
    dp[0][0][0]=0;
    // rep(i, n){
    //     if(a[i]>x)dp[1][1][x+1]=b[i];
    //     else chmin(dp[1][1][a[i]], b[i]);
    // }
    rep2(1, i, n+1){
        dp[i][0][0]=0;
        rep(j, n){
            rep(k, x+1){
                if(dp[i-1][j][k]!=inf){
                    chmin(dp[i][j][k], dp[i-1][j][k]);
                    if(dp[i-1][j][k]>y)continue;
                    if(k+a[i-1]>x)dp[i][j+1][x+1]=b[i-1];
                    else chmin(dp[i][j+1][k+a[i-1]], dp[i-1][j][k]+b[i-1]);
                }
            }
        }
    }
    // rep(i, n+1){
    //     rep(j, n+1){
    //         rep(k, x+2){
    //             if(dp[i][j][k]!=inf)cout<<dp[i][j][k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    // coc2(ta, tb);
    ll ans=0;
    rrep(j, n+1){
        rep(k, x+2){
            if(dp[n][j][k]!=inf){
                if(j!=n and k<=x and dp[n][j][k]<=y)chmax(ans, j+1);
                else chmax(ans, j);
            }
        }
    }
    cout<<ans<<endl;
}