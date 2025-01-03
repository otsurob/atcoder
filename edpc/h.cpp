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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll mod=1000000007;
    ll h, w;
    cin>>h>>w;
    vector<string> a(h);
    cinv(a, h);
    vector<vector<ll>> dp(h, vector<ll>(w, 0));
    dp[0][0]=1;
    rep(i, h){
        rep(j, w){
            if(a[i][j]=='#')continue;
            if(i!=0)dp[i][j]+=dp[i-1][j];
            if(j!=0)dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    cout<<dp[h-1][w-1]%mod<<endl;
}