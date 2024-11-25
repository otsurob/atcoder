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
    ll n;
    string s;
    cin>>n>>s;
    vector<vector<ll>> dp(n+1, vector<ll>(3, 0));
    rep(i, n){
       if(s[i]=='R'){
        dp[i+1][0]=max(dp[i][1], dp[i][2]);
        dp[i+1][1]=max(dp[i][0]+1, dp[i][2]+1);
       }else if(s[i]=='P'){
        dp[i+1][1]=max(dp[i][0], dp[i][2]);
        dp[i+1][2]=max(dp[i][0]+1, dp[i][1]+1);
       }else{
        dp[i+1][0]=max(dp[i][1]+1, dp[i][2]+1);
        dp[i+1][2]=max(dp[i][0], dp[i][1]);
       }
    //    coc3(dp[i+1][0], dp[i+1][1], dp[i+1][2]);
    }
    ll ans=0;
    rep(i, 3)ans=max(ans, dp[n][i]);
    cout<<ans<<endl;
}