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
    ll x, y, z;
    cin>>x>>y>>z;
    string s;
    cin>>s;
    vector<vector<ll>> dp(s.length(), vector<ll>(2));
    if(s[0]=='a'){
        dp[0][0]=x;
        dp[0][1]=z+y;
    }else{
        dp[0][0]=y;
        dp[0][1]=z+x;
    }
    rep2(1, i, s.length()){
        if(s[i]=='a'){
            dp[i][0]=min(dp[i-1][0]+x, dp[i-1][1]+z+x);
            dp[i][1]=min(dp[i-1][0]+z+y, dp[i-1][1]+y);
        }else{
            dp[i][0]=min(dp[i-1][0]+y, dp[i-1][1]+z+y);
            dp[i][1]=min(dp[i-1][0]+z+x, dp[i-1][1]+x);
        }
        // coc2(dp[i][0], dp[i][1])
    }
    cout<<min(dp[s.length()-1][0], dp[s.length()-1][1])<<endl;
}