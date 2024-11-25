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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i, n) cin>>a[i];
    vector<vector<ll>> dp(n, vector<ll> (10, 0));
    dp[0][a[0]]=1;
    rep(i, n-1)rep(j, 10){
        // if(dp[i][j]==0) continue;
        if(dp[i][j]>=998244353) dp[i][j]%=998244353;
        dp[i+1][(j+a[i+1])%10]+=dp[i][j];
        dp[i+1][(j*a[i+1])%10]+=dp[i][j];
    }
    rep(i, 10) cout<<(ll) dp[n-1][i]%998244353<<endl;
}