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

ll n;
vector<vector<ll>> g;
vector<ll> ans;
vector<bool> seen;

void dfs(ll m){
    for(auto x : g[m]){
        if(!seen[x]){
            if(g[x].empty()){
                ans.push_back(x);
                seen[x]=true;
                continue;
            }
            else{
                seen[x]=true;
                dfs(x);
                ans.push_back(x);
            }
        }
    }
}


int main(){
    cin>>n;
    g.resize(n);
    rep(i, n){
        ll c;
        cin>>c;
        vector<ll> p(c, 0);
        cinv(p, c);
        rep(j, c){
            p[j]--;
            g[i].push_back(p[j]);
        }
    }
    seen.resize(n, false);
    dfs(0);
    rep(i, ans.size())cout<<ans[i]+1<<" ";
    cout<<endl;
}