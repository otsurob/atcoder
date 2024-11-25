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
    ll n1, n2, m;
    cin>>n1>>n2>>m;
    ll a, b;
    vector<vector<ll>> g(n1+n2); 
    rep(i, m){
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        }
    vector<ll> d(n1+n2, -1);
    vector<bool> seen(n1+n2, false);
    queue<pll> q;
    q.push(pll(0, 0));
    seen[0]=true;
    d[0]=0;
    while(!q.empty()){
        ll x=q.front().fst, y=q.front().snd;
        q.pop();
        for(auto z : g[x]){
            if(!seen[z]){
                q.push(pll(z, y+1));
                seen[z]=true;
                d[z]=y+1;
            }
        }
    }
    ll n=n1+n2;
    q.push(pll(n-1, 0));
    seen[n-1]=true;
    d[n-1]=0;
    while(!q.empty()){
        ll x=q.front().fst, y=q.front().snd;
        q.pop();
        for(auto z : g[x]){
            if(!seen[z]){
                q.push(pll(z, y+1));
                seen[z]=true;
                d[z]=y+1;
            }
        }
    }
    ll mx1=-1, mx2=-1;
    rep(i, n1) mx1=max(mx1, d[i]);
    rep2(n1, i, n) mx2=max(mx2, d[i]);
    cout<<(ll)mx1+mx2+1<<endl;
}