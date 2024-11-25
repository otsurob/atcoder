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
    ll n, m, k;
    cin>>n>>m>>k;
    ll mod=998244353;
    vector<vector<ll>> dp(n, vector<ll>(m+1, 0));
    vector<vector<ll>> ns(n, vector<ll>(m+1, 0));
    if(k==0){
        ll ans=1;
        rep(i, n)ans=(ans*m)%mod;
        cout<<ans<<endl;
        return 0;
    }
    ns[0][0]=0;
    rep2(1, i, m+1)ns[0][i]=ns[0][i-1]+1;
    rep2(1, i, m+1)dp[0][i]=1; 
    rep2(1, i, n){
        rep2(1, j, m+1){
            dp[i][j]=(ns[i-1][m]-(ns[i-1][min(m, j+k-1)]-ns[i-1][max(0ll, j-k)])+mod)%mod;
            ns[i][j]=(ns[i][j-1]+dp[i][j])%mod;
        }
    }
    // rep(i, n){
    //     rep(j, m+1){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // rep(i, n){
    //     rep(j, m+1){
    //         cout<<ns[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<ns[n-1][m]<<endl;
}