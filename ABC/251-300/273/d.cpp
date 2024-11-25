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
    ll h, w, rs, cs, n, q;
    cin>>h>>w>>rs>>cs>>n;
    rs--, cs--;
    vector<ll> r(n), c(n);
    rep(i, n){
        cin>>r[i]>>c[i];
        r[i]--, c[i]--;
    }
    cin>>q;
    vector<char> d(q);
    vector<ll> l(q);

    rep(i, q)cin>>d[i]>>l[i];
    // vector<set<ll>> t(w), y(h);
    // map<ll, set<ll>> t, y;
    map<ll, vector<ll>> t, y;
    // rep(i, w)t[i].insert(-1);
    // rep(i, h)y[i].insert(-1);
    // rep(i, w)t[i].insert(h);
    // rep(i, h)y[i].insert(w);
    // rep(i, n){
    //     y[r[i]].insert(c[i]);
    //     t[c[i]].insert(r[i]);
    // }
    rep(i, n){
        y[r[i]].push_back(c[i]);
        t[c[i]].push_back(r[i]);
    }
    // for(auto x : t){
    //     t[x.fst].insert(-1);
    //     t[x.fst].insert(h);
    // }
    // for(auto x : y){
    //     y[x.fst].insert(-1);
    //     y[x.fst].insert(w);
    // }
    for(auto x : t){
        t[x.fst].push_back(-1);
        t[x.fst].push_back(h);
        sort(t[x.fst].begin(), t[x.fst].end());
    }
    for(auto x : y){
        y[x.fst].push_back(-1);
        y[x.fst].push_back(w);
        sort(y[x.fst].begin(), y[x.fst].end());
    }
    // rep(i, h){
    //     for(auto x : y[i])cout<<x<<" ";
    //     cout<<endl;
    // }
    // rep(i, w){
    //     for(auto x : t[i])cout<<x<<" ";
    //     cout<<endl;
    // }
    rep(i, q){
        if(d[i]=='L'){
            if(y.find(rs)!=y.end()){
                auto it = lower_bound(y[rs].begin(), y[rs].end(), cs);
                it--;
                cs=cs-min(l[i], cs-1-*it);
            }else{
                cs=cs-min(l[i], cs);
            }
        }
        if(d[i]=='R'){
            if(y.find(rs)!=y.end()){
                auto it = lower_bound(y[rs].begin(), y[rs].end(), cs);
                // it--;
                cs=cs+min(l[i], *it-cs-1);
            }else{
                cs=cs+min(l[i], w-1-cs);
            }
        }
        if(d[i]=='U'){
            if(t.find(cs)!=t.end()){
                auto it = lower_bound(t[cs].begin(), t[cs].end(), rs);
                it--;
                // coc(*it)
                // for(auto x : t[cs])cout<<x<<" ";
                // cout<<endl;
                rs=rs-min(l[i], rs-1-*it);
            }else{
                rs=rs-min(l[i], rs);
            }
        }
        if(d[i]=='D'){
            if(t.find(cs)!=t.end()){
                auto it = lower_bound(t[cs].begin(), t[cs].end(), rs);
                // it--;
                // for(auto x : t[cs])cout<<x<<" ";
                // cout<<endl;
                rs=rs+min(l[i], *it-1-rs);
                // coc(*it)
            }else{
                rs=rs+min(l[i], h-1-rs);
            }
        }
        coc2(rs+1, cs+1);
    }
}