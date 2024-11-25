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
    vector<vector<ll>> a(2*n, vector<ll>(2*n, 0));
    rep(i, 2*n-1){
        rep2(i+1, j, 2*n){
            cin>>a[i][j];
        }
    }
    vector<ll> dp(1<<(2*n), 0);
    rep(i, (1<<2*n)-1){
        ll l=-1;
        rep(j, 2*n){
            if(!(i&(1<<j))){
                l=j;
                break;
            }
        }
        rep(j, 2*n){
            if(j==l)continue;
            if(!(i&(1<<j))){
                ll nx=i|(1<<l)|(1<<j);
                // if(i==0)coc2(a[l][j], nx)
                chmax(dp[nx], dp[i]+a[l][j]);
            }
        }
    }
    rep(i, 1<<2*n){
        cout<<dp[i]<<" ";
    }
    codl()
    cout<<dp[(1<<2*n)-1]<<endl;
}