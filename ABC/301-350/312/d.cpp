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
    string s;
    cin>>s;
    ll n=s.length();
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    if(s[0]==')'){
        cout<<0<<endl;
        return 0;
    }
    ll mod=998244353;
    dp[0][1]=1;
    rep2(1, i, n){
        if(s[i]=='('){
            rep(j, n-1)dp[i][j+1]+=dp[i-1][j]%mod;
        }
        if(s[i]==')'){
            rep2(1, j, n)dp[i][j-1]+=dp[i-1][j]%mod;
        }
        if(s[i]=='?'){
            rep(j, n-1)dp[i][j+1]+=dp[i-1][j]%mod;
            rep2(1, j, n)dp[i][j-1]+=dp[i-1][j]%mod;
        }
        // rep(k, n)cout<<dp[i][k]<<" ";
        // cout<<endl;
    }
    cout<<dp[n-1][0]%mod<<endl;
}