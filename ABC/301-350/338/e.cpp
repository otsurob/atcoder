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
#define inf 999999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll n;
    cin>>n;
    vector<ll> a(n), b(n);
    vector<pll> g(n);
    map<pll, bool> mp;
    rep(i, n){
        cin>>a[i]>>b[i];
        a[i]--, b[i]--;
        mp[pll(a[i], b[i])]=true;
        mp[pll(b[i], a[i])]=true;
        g[i]=pll(a[i], b[i]);
    }
    vector<ll> fv(2*n), bv(2*n);
    rep(i, 2*n){
        fv[i]=(i+1)%(2*n);
        bv[i]=(i-1+(2*n))%(2*n);
    }
    // coutv(fv, n)
    // codl()
    // coutv(bv, n)
    // codl()
    ll cnt=0;
    queue<pll> q;
    rep(i, n){
        if((fv[g[i].fst]==g[i].snd) or (fv[g[i].snd]==g[i].fst)){
            // coc4(g[i].fst, g[i].snd, fv[g[i].fst], fv[g[i].snd])
            q.push(g[i]);
        }
    }
    while(!q.empty()){
        ll x=q.front().fst, y=q.front().snd;
        // coc2(x, y)
        q.pop();
        cnt++;
        if(cnt==n){
            coutn()
            return 0;
        }
        // coc4(fv[x], bv[x], fv[y], bv[y]);
        if(fv[y]==x)swap(x, y);
        fv[bv[x]]=fv[y];
        bv[fv[y]]=bv[x];
        // coc2(bv[x], fv[y]);
        if(mp[pll(bv[x], fv[y])])q.push(pll(bv[x], fv[y]));
    }
    couty()
}