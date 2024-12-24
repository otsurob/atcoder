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
    vector<ll> p(n);
    cinv(p, n);
    vector<ld> x(5001), y(5002), k(5001);
    ld now=1;
    rep(i, 5001){
        x[i]=now;
        now*=0.9;
        if(i==0)continue;
        k[i]=1200/(sqrt(i));
    }
    y[0]=0;
    rep2(1, i, 5002)y[i]=y[i-1]+x[i-1];
    vector<vector<ld>> dp(n+1, vector<ld>(n+1, -inf));
    dp[1][1]=p[n-1]-1200;
    rep2(2, i, n+1){
        rep2(1, j, n+1){
            if(j>i)continue;
            if(j==1)dp[i][1]=max(dp[i-1][1], (ld)p[n-i]-1200);
            else dp[i][j]=max(dp[i-1][j], (((dp[i-1][j-1]+k[j-1])*y[j-1]+p[n-i]*x[j-1])/y[j])-k[j]);
            if(i==2 and j==2){
                // wow()
                // coc4(dp[i-i][j], dp[i-1][j-1], k[j-1], y[j-1])
            }
        }
    }
    // rep(i, n+1){
    //     rep(j, n+1){
    //         cout<<fixed<<setprecision(15)<<dp[i][j]<<" ";
    //     }
    //     codl()
    // }
    ld mx=-inf;
    rep(i, n+1)mx=max(mx, dp[n][i]);
    decout(mx);
}