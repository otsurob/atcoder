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
    ll n;
    cin>>n;
    vector<vector<ll>> g(n);
    rep(i, n-1){
        ll u, v;
        cin>>u>>v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll sta;
    rep(i, n)if(g[i].size()==1)sta=i;
    vector<bool> seen(n);
    queue<ll> q;
    q.push(sta);
    vector<ll> ans;
    seen[sta]=true;
    while(!q.empty()){
        ll x = q.front(), y=-1;
        queue<ll> z;
        q.pop();
        for(auto t : g[x]){
            if(!seen[t]){
                y=t;
                seen[t]=true;
            }
        }
        if(y==-1)break;
        ans.push_back(g[y].size());
        for(auto p : g[y]){
            if(!seen[p] and g[p].size()==2){
                z.push(p);
            }
            seen[p]=true;
        }
        while(!z.empty()){
            ll zz=z.front();
            z.pop();
            for(auto w : g[zz]){
                if(!seen[w]){
                    q.push(w);
                    seen[w]=true;
            }
            }
        }
    }
    sort(ans.begin(), ans.end());
    rep(i, ans.size())cout<<ans[i]<<" ";
    cout<<endl;
}