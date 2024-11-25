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
    ll n, s;
    cin>>n>>s;
    vector<ll> a(n), b(n), c(n);
    rep(i, n)cin>>a[i]>>b[i];
    ll sum=0;
    rep(i, n)sum+=min(a[i], b[i]);
    rep(i, n)c[i]=abs(a[i]-b[i]);
    vector<vector<string>> dp(n, vector<string>(s+1, ""));
    dp[0][a[0]].push_back('H');
    if(a[0]!=b[0])dp[0][b[0]].push_back('T');
    rep2(1, i, n){
        rep(j, s+1){
            if(dp[i-1][j]!=""){
                if(j+a[i]<=s){
                    dp[i][j+a[i]]=dp[i-1][j];
                    dp[i][j+a[i]].push_back('H');
                }
                if(j+b[i]<=s){
                    dp[i][j+b[i]]=dp[i-1][j];
                    dp[i][j+b[i]].push_back('T');
                }
            }
        }
    }
    if(dp[n-1][s]=="")coutn()
    else{
        couty()
        cout<<dp[n-1][s]<<endl;
    }
}