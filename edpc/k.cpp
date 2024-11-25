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
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    cinv(a, n);
    vector<bool> dp(k+1, false);
    ll mn=9999999999, mx=0;
    rep(i, n){
        chmax(mx, a[i]);
        chmin(mn, a[i]);
    }
    rep(i, mn)dp[i]=false;
    rep(i, k+1){
        rep(j, n){
            if(i+a[j]<=k){
                if(!dp[i])dp[i+a[j]]=true;
            }
        }
    }
    // rep(i, k+1)cout<<dp[i]<<" ";
    // cout<<endl;
    if(dp[k])cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}