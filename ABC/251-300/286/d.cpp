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
    ll n, x;
    cin>>n>>x;
    vector<pll> m;
    vector<ll> a(n), b(n);
    rep(i, n)cin>>a[i]>>b[i];
    vector<vector<bool>> dp(n+1, vector<bool>(x+1, false));
    dp[0][0]=true;
    rep(i, n){
        rep(j, x+1){
            rep(k, b[i]+1){
                if(dp[i][j] and j+a[i]*k<=x){
                    dp[i+1][j+a[i]*k]=true;
                }
            }
        }
    }
    if(dp[n][x])couty()
    else coutn()
}