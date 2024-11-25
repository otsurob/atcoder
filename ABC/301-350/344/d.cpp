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
#define pll pair<ll, ll>
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    string t;
    cin>>t;
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<vector<string>> s(n);
    rep(i, n){
        cin>>a[i];
        s[i].resize(a[i]);
        rep(j, a[i]) cin>>s[i][j];
    }
    vector<vector<ll>> dp(n, vector<ll>(t.length()+1, 1000));
    dp[0][0]=0;
    rep(j, t.length()+1){
        string z = t.substr(0, j);
        rep(l, a[0]){
            if(z==s[0][l]) dp[0][j]=1;
        }
    }
    rep2(1, i, n){
        rep(j, t.length()+1){
            rep(k, j){
                string z = t.substr(k, j-k);
                rep(l, a[i]){
                    if(z==s[i][l]){
                        dp[i][j]=min(dp[i][j], dp[i-1][k]+1);
                    }
                }
            }
            if(dp[i-1][j]!=1000) dp[i][j]=min(dp[i][j], dp[i-1][j]);
        }
        // cout<<dp[i]<<endl;
    }
    if(dp[n-1][t.length()]==1000) cout<<-1<<endl;
    else cout<<dp[n-1][t.length()]<<endl;
}