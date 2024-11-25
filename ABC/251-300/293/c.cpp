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

ll h, w, ans=0;
vector<ll> road;
vector<vector<ll>> g;
set<ll> st;

void dfs(ll x, ll y){
    road.push_back(g[y][x]);
    // cout<<g[y][x]<<endl;
    if(x+1<w) dfs(x+1, y);
    if(y+1<h) dfs(x, y+1);
    if(road.size()==h+w-1){
        // rep(i, road.size()) cout<<road[i]<<" ";
        // cout<<endl;
        rep(i, road.size()) st.insert(road[i]);
        if(st.size()==h+w-1) ans++;
        st={};
        // rep(i, road.size()) cout<<road[i]<<" ";
        // cout<<endl;
    }
    road.pop_back();
}


int main(){
    cin>>h>>w;
    g.resize(h);
    rep(i, h){
        g[i].resize(w);
        rep(j, w) cin>>g[i][j];
    }
    dfs(0, 0);
    cout<<ans<<endl;
}