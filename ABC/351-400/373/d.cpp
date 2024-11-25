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
vector<ll> topological(vector<vector<ll>> g, vector<ll> indegree){
    vector<ll> sorted_vector;
    ll tn=g.size();
    queue<ll> q;
    rep(i, tn){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        ll tv=q.front();
        q.pop();
        // その頂点と隣接している頂点の入次数を減らし、0になればキューに追加
        rep(i, g[tv].size()) {
            int tu = g[tv][i];
            indegree[tu] -= 1;
            if (indegree[tu] == 0) q.push(tu);
        }
        sorted_vector.push_back(tv);
    }
    return sorted_vector;
}
int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> g(n);
    vector<vector<pll>> p(n);
    vector<ll> ind(n, 0);
    vector<ll> u(m), v(m), w(m);
    rep(i, m){
        cin>>u[i]>>v[i]>>w[i];
        u[i]--, v[i]--;
        if(w[i]<0){
            g[v[i]].push_back(u[i]);
            p[u[i]].push_back(pll(v[i], w[i]));
            p[v[i]].push_back(pll(u[i], abs(w[i])));
            ind[u[i]]++;
        }
        else{
            g[u[i]].push_back(v[i]);
            p[u[i]].push_back(pll(v[i], w[i]));
            p[v[i]].push_back(pll(u[i], -w[i]));
            ind[v[i]]++;
        }
    }
    vector<ll> tv=topological(g, ind);
    // rep(i, n)cout<<tv[i]<<" ";
    // cout<<endl;
    vector<ll> ans(n, 0);
    vector<bool> seen(n, false);
    // seen[tv[0]]=true;
    queue<ll> q;
    rep(i, n){
        if(seen[tv[i]])continue;
        seen[tv[i]]=true;
        q.push(tv[i]);
        ans[tv[i]]=0;
        while(!q.empty()){
            ll x = q.front();
            q.pop();
            for(pll z : p[x]){
                if(seen[z.fst])continue;
                ans[z.fst]=ans[x]+z.snd;
                q.push(z.fst);
                seen[z.fst]=true;
            }
        }
    }
    rep(i, n)cout<<ans[i]<<" ";
    cout<<endl;
}