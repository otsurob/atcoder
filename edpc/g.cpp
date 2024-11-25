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
    vector<ll> x(m), y(m);
    vector<vector<ll>> g(n);
    vector<ll> c(n, 0);
    rep(i, m){
        cin>>x[i]>>y[i];
        x[i]--, y[i]--;
        g[x[i]].push_back(y[i]);
        c[y[i]]++;
    }
    vector<ll> sa;
    sa=topological(g, c);
    vector<ll> dp(n, 0);
    rep(i, n){
        for(ll x : g[sa[i]]){
            chmax(dp[x], dp[sa[i]]+1);
        }
    }
    cout<<dp[sa[n-1]]<<endl;

}