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

ll inf=999999999999;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<vector<ll>>> g(n);
    ll a, b, x, y;
    rep(i, m){
        cin>>a>>b>>x>>y;
        g[a-1].push_back({b-1, x, y});
        x*=-1;
        y*=-1;
        g[b-1].push_back({a-1, x, y});
    }
    vector<pll> s(n, pll(inf, inf));
    s[0]=pll(0, 0);
    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        ll z=q.front();
        q.pop();
        ll nx=s[z].fst, ny=s[z].snd;
        for(auto t : g[z]){
            if(s[t[0]].fst==inf){
                s[t[0]]=pll(nx+t[1], ny+t[2]);
                q.push(t[0]);
            }
        }
    }
    rep(i, n){
        if(s[i].fst==inf) cout<<"undecidable"<<endl;
        else cout<<s[i].fst<<" "<<s[i].snd<<endl;
    }
}