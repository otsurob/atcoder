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
    ll n, d;
    cin>>n>>d;
    vector<ll> x(n), y(n);
    rep(i, n) cin>>x[i]>>y[i];
    ll xz=x[0], yz=y[0];
    d=d*d;
    vector<vector<ll>> ans(n);
    rep(i, n){
        rep(j, n){
            if(i==j) continue;
            if(((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j]))<=d) ans[i].push_back(j);
        }
    }
    vector<bool> seen(n, false), p(n, false);
    queue<ll> q;
    q.push(0);
    p[0]=true;
    while(!q.empty()){
        ll a=q.front();
        q.pop();
        for(auto b : ans[a]){
            if(!seen[b]){
                p[b]=true;
                seen[b]=true;
                q.push(b);
            }
        }
    }
    rep(i, n){
        if(p[i]) couty()
        else coutn()
    }
}