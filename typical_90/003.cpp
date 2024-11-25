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


vector<ll> dfs(vector<vector<ll>> gg, ll s){
    ll m=gg.size();
    vector<ll> dis(m, -1);
    vector<ll> od;
    od.push_back(s);
    dis[s]=0;
    while(!od.empty()){
        ll x=od.back();
        od.pop_back();
        for(auto y : gg[x]){
            if(dis[y]==-1){
                od.push_back(y);
                dis[y]=dis[x]+1;
            }

        }
    }
    return dis;
}

int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> g(n);
    ll a, b;
    rep(i, n-1){
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> ans=dfs(g, 0);

    ll mx=-1;
    ll mxn=0;
    rep(i, ans.size()){
        if(mx<ans[i]){
            mx=ans[i];
            mxn=i;
        }
    }
    ans=dfs(g, mxn);
    rep(i, ans.size()) mx=max(mx, ans[i]);
    cout<<mx+1<<endl;
}