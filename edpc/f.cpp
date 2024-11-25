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
    string s, t;
    cin>>s>>t;
    ll n=s.length(), m=t.length();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    rep2(1, i, n+1){
        rep2(1, j, m+1){
            if(i>0 and j>0){
                if(s[i-1]==t[j-1])chmax(dp[i][j], dp[i-1][j-1]+1);
                else{
                    chmax(dp[i][j], dp[i-1][j]);
                    chmax(dp[i][j], dp[i][j-1]);
                }
            }else{
                if(i>0)chmax(dp[i][j], dp[i-1][j]);
                if(j>0)chmax(dp[i][j], dp[i][j-1]);
            }
        }
    }
    string ans="";
    while(n>0 and m>0){
        if(dp[n][m]==dp[n-1][m]){
            n--;
        }else if(dp[n][m]==dp[n][m-1]){
            m--;
        }else if(dp[n][m]==dp[n-1][m-1]+1){
            ans=s[n-1]+ans;
            n--, m--;
        }
    }
    cout<<ans<<endl;
}