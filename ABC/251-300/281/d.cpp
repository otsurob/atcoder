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
    ll n, k, d;
    cin>>n>>k>>d;
    vector<ll> a(n);
    cinv(a, n);
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(k+1, vector<ll>(d, -1)));
    dp[0][0][0]=0;
    rep(i, n){
        rep(j, k+1){
            rep(l, d){
                // cout<<dp[i][j][l]<<" ";
                if(dp[i][j][l]==-1)continue;
                dp[i+1][j][l]=max(dp[i+1][j][l], dp[i][j][l]);
                if(j!=k)dp[i+1][j+1][(l+a[i])%d]=max(dp[i+1][j+1][(l+a[i])%d], dp[i][j][l]+a[i]);
            }
            // cout<<endl;
        }
        // cout<<endl;
    }
    cout<<dp[n][k][0]<<endl;
}