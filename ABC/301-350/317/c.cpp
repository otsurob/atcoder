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


ll sum=0;
vector<bool> seen(11, false);
vector<vector<ll>> e(11, vector<ll>(11, 0));


void dfs(ll v, ll s){
    // cout<<v<<" "<<s<<endl;
    seen[v]=true;
    sum=max(sum, s);
    rep(i, 11){
        if(!seen[i] and e[v][i]!=0) dfs(i, s+e[v][i]);
    }
    seen[v]=false;
    // cout<<sum<<endl;
}

int main(){
    ll n, m;
    cin>>n>>m;
    ll a, b, c;
    rep(i, m){
        cin>>a>>b>>c;
        a--;
        b--;
        e[a][b]=c;
        e[b][a]=c;
    }
    rep(j, n){
        vector<bool> seen(11, false);
        dfs(j, 0);
    }
    cout<<sum<<endl;
}