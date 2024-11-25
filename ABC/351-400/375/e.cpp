#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<' ';
#define codl() cout<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
#define decout(a) cout<<fixed<<setprecision(15)<<a<<endl;
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
    ll n;
    cin>>n;
    vector<ll> a(n), b(n);
    rep(i, n)cin>>a[i]>>b[i];
    ll sum=0;
    rep(i, n)sum+=b[i];
    if(sum%3!=0){
        cout<<-1<<endl;
        return 0;
    }
    sum/=3;
    ll inf=999999999999999;
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(sum+2, vector<ll>(sum+2, inf)));
    dp[0][0][0]=0;
    rep(i, n){
        rep(j, sum+1){
            rep(k, sum+1){
                if(dp[i][j][k]!=inf){
                    if(a[i]==1){
                        chmin(dp[i+1][min(j+b[i], sum+1)][k], dp[i][j][k]);
                        chmin(dp[i+1][j][min(k+b[i], sum+1)], dp[i][j][k]+1);
                        chmin(dp[i+1][j][k], dp[i][j][k]+1);
                    }
                    if(a[i]==2){
                        chmin(dp[i+1][min(j+b[i], sum+1)][k], dp[i][j][k]+1);
                        chmin(dp[i+1][j][min(k+b[i], sum+1)], dp[i][j][k]);
                        chmin(dp[i+1][j][k], dp[i][j][k]+1);
                    }
                    if(a[i]==3){
                        chmin(dp[i+1][min(j+b[i], sum+1)][k], dp[i][j][k]+1);
                        chmin(dp[i+1][j][min(k+b[i], sum+1)], dp[i][j][k]+1);
                        chmin(dp[i+1][j][k], dp[i][j][k]);
                    }
                }
            }
        }
    }
    if(dp[n][sum][sum]==inf)cout<<-1<<endl;
    else cout<<dp[n][sum][sum]<<endl;
}