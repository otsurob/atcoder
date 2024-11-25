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
    ll h, w, n, a, b;
    cin>>w>>h>>n;
    vector<ll> p(n), q(n);
    rep(i, n)cin>>p[i]>>q[i];
    cin>>a;
    vector<ll> va(a);
    cinv(va, a);
    cin>>b;
    vector<ll> vb(b);
    cinv(vb, b);
    map<pll, ll> mp;
    va.push_back(w), vb.push_back(h);
    rep(i, n){
        auto it1=upper_bound(va.begin(), va.end(), p[i]);
        auto it2=upper_bound(vb.begin(), vb.end(), q[i]);
        mp[pll(*it1, *it2)]++;
        // coc2(*it1, *it2)
    }
    ll mn=9999999999, mx=-1;
    ll tmp=(a+1)*(b+1);
    if(mp.size()!=tmp)mn=0;
    // for(auto iter=mp.begin(); iter!=mp.end(); iter++){
    //     mn=min(mn, iter->second);
    //     mx=max(mx, iter->second);
    // }
    for(auto x : mp){
        mn=min(mn, x.second);
        mx=max(mx, x.second);
    }
    cout<<mn<<" "<<mx<<endl;
}