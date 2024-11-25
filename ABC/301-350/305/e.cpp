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
    ll n, m, k;
    cin>>n>>m>>k;
    vector<vector<ll>> g(n);
    rep(i, m){
        ll a, b;
        cin>>a>>b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> c(n, -1);
    priority_queue<pll> pq;
    rep(i, k){
        ll p, h;
        cin>>p>>h;
        p--;
        pq.push(pll(h, p));
        c[p]=h;
    }
    while(!pq.empty()){
        ll th=pq.top().fst, tp=pq.top().snd;
        pq.pop();
        if(th==0)continue;
        for(ll x : g[tp]){
            if(c[x]>=th-1)continue;
            c[x]=th-1;
            pq.push(pll(th-1, x));
        }
    }
    ll cnt=0;
    vector<ll> ans;
    rep(i, n){
        if(c[i]!=-1){
            cnt++;
            ans.push_back(i+1);
        }
    }
    cout<<cnt<<endl;
    rep(i, ans.size())cout<<ans[i]<<" ";
    cout<<endl;
}