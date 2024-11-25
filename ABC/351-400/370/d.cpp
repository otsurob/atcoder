#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<' ';
#define codl() cout<<endl;
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
int main(){
    ll h, w, q;
    cin>>h>>w>>q;
    vector<ll> r(q), c(q);
    rep(i, q)cin>>r[i]>>c[i];
    rep(i, q)r[i]--, c[i]--;
    vector<set<ll>> hs(h), vs(w);
    rep(i, h)rep(j, w)hs[i].insert(j);
    rep(i, w)rep(j, h)vs[i].insert(j);
    ll ans=h*w;
    ll p=0;
    // vector<vector<bool>> ex(h, vector<bool>(w, true));
    rep(i, q){
        vector<pll> hsd={}, vsd={};
        if(hs[r[i]].find(c[i])!=hs[r[i]].end() and vs[c[i]].find(r[i])!=vs[c[i]].end()){
            // ex[r[i]][c[i]]=false;
            ans--;
            hs[r[i]].erase(c[i]);
            vs[c[i]].erase(r[i]);
            // continue;
        }
        else{
            auto it1 = hs[r[i]].lower_bound(c[i]);
            auto it2 = vs[c[i]].lower_bound(r[i]);
            // if(it2==vs[c[i]].begin()){
            //     cout<<"wow"<<*it2<<endl;
            // }
            if(it1!=hs[r[i]].end()){
                // hs[r[i]].erase(*it1);
                // vs[*it1].erase(r[i]);
                hsd.push_back(pll(r[i], *it1));
                vsd.push_back(pll(*it1, r[i]));
                ans--;
                // p++;
            }
            if(it1!=hs[r[i]].begin()){
                it1--;
                // hs[r[i]].erase(*it1);
                // vs[*it1].erase(r[i]);
                hsd.push_back(pll(r[i], *it1));
                vsd.push_back(pll(*it1, r[i]));
                ans--;
                // p++;
            }
            if(it2!=vs[c[i]].end()){
                // vs[c[i]].erase(*it2);
                // hs[*it2].erase(c[i]);
                hsd.push_back(pll(*it2, c[i]));
                vsd.push_back(pll(c[i], *it2));
                ans--;
                // p++;
            }
            if(it2!=vs[c[i]].begin()){
                it2--;
                // vs[c[i]].erase(*it2);
                // hs[*it2].erase(c[i]);
                hsd.push_back(pll(*it2, c[i]));
                vsd.push_back(pll(c[i], *it2));
                ans--;
                // p++;
            }
        }
        for(pll x : hsd)hs[x.fst].erase(x.snd);
        for(pll x : vsd)vs[x.fst].erase(x.snd);
        // rep(j, h){
        //     for(ll x : hs[j])cout<<x<<" ";
        //     codl();
        // }
        // rep(j, w){
        //     for(ll x : vs[j])cout<<x<<" ";
        //     codl();
        // }
        // codl();
        // cout<<p<<endl;
    }
    // rep(i, h)ans+=hs[i].size();
    cout<<ans<<endl;
}