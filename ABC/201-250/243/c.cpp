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
int main(){
    ll n;
    cin>>n;
    vector<ll> x(n), y(n);
    rep(i, n)cin>>x[i]>>y[i];
    string s;
    cin>>s;
    map<ll, vector<pair<ll, char>>> mp;
    rep(i, n){
        mp[y[i]].push_back(pair<ll, char>(x[i], s[i]));
    }
    for(auto i : mp){
        ll l=-1, r=99999999999999;
        for(auto z : mp[i.fst]){
            // coc3(i.fst, z.fst, z.snd)
            if(z.snd=='L')chmax(l, z.fst);
            if(z.snd=='R')chmin(r, z.fst);
        }
        if(r<l){
            couty()
            return 0;
        }
    }
    coutn()
}