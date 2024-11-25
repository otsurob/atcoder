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
#define inf 9999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }


ll n, m;
vector<ll> a, b;
vector<vector<ll>> g;
vector<bool> seen;
ll ans=inf;

void dfs(ll x, ll c, ll from){
    for(ll z : g[x]){
        if(z==from)continue;
        if(seen[z]){
            if(z==0){
                chmin(ans, c+1);
                continue;;
            }else{
                continue;;
            }
        }
        seen[z]=true;
        dfs(z, c+1, x);
        seen[z]=false;
    }
}


int main(){
    // ll n, m;
    cin>>n>>m;
    // vector<ll> a(m), b(m);
    a.resize(m);
    b.resize(m);
    // vector<vector<ll>> g(n);
    g.resize(n);
    rep(i, m){
        cin>>a[i]>>b[i];
        a[i]--, b[i]--;
        g[a[i]].push_back(b[i]);
        // g[b[i]].push_back(a[i]);
    }
    seen.resize(n, false);
    seen[0]=true;
    dfs(0, 0, -1);
    if(ans==inf)cout<<-1<<endl;
    else cout<<ans<<endl;
}