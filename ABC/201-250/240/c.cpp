#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
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
    ll n, x;
    cin>>n>>x;
    ll m=10000;
    vector<ll> a(n), b(n);
    rep(i, n)cin>>a[i]>>b[i];
    vector<vector<bool>> g(n, vector<bool>(m+1));
    g[0][a[0]]=true;
    g[0][b[0]]=true;
    rep2(1, i, n){
        rep(j, m+1){
            if(g[i-1][j]){
                if(j+a[i]<=m)g[i][j+a[i]]=true;
                if(j+b[i]<=m)g[i][j+b[i]]=true;
            }
        }
    }
    if(g[n-1][x])couty()
    else coutn()
}