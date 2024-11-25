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
    ll inf=999999999999999;
    ll n;
    cin>>n;
    vector<ll> a(n);
    cinv(a, n);
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    vector<ll> s(n+1, 0);
    rep(i, n)s[i+1]=s[i]+a[i];
    rep2(1, i, n)dp[i-1][i]=a[i]+a[i-1];
    rep2(2, m, n){
        rep(l, n){
            if(l+m>=n)break;
            ll r=l+m;
            ll mn=inf;
            ll cost=s[r+1]-s[l];
            rep2(l, k, r){
                chmin(mn, cost+dp[l][k]+dp[k+1][r]);
            }
            dp[l][r]=mn;
            // coc4(l, r, mn, cost)
        }
    }
    // rep(i, n){
    //     rep(j, n){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[0][n-1]<<endl;
}