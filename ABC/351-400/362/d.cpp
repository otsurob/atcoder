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
    ll n, m;
    cin>>n>>m;
    vector<ll> a(n);
    cinv(a, n);
    vector<ll> u(m), v(m), b(m);
    vector<vector<pll>> g(n);
    rep(i, m){
        cin>>u[i]>>v[i]>>b[i];
        u[i]--, v[i]--;
        g[u[i]].push_back(pll(v[i], b[i]));
        g[v[i]].push_back(pll(u[i], b[i]));
    }
    vector<ll> cost(n, 99999999999999999);
    cost[0]=a[0];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    // priority_queue<pll> pq;
    pq.push(pll(cost[0], 0));
    while(!pq.empty()){
        ll c=pq.top().fst, z=pq.top().snd;
        // cout<<z<<endl;
        pq.pop();
        // cout<<c<<endl;
        if(cost[z]<c)continue;
        for(auto x : g[z]){
            ll xz=x.fst, xc=c+x.snd+a[xz];
            if(cost[xz]<=xc)continue;
            cost[xz]=xc;
            pq.push(pll(xc, xz));
        }
    }
    rep2(1, i, n)cout<<cost[i]<<" ";
    cout<<endl;
}