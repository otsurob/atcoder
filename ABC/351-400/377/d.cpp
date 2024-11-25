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
    ll n, m;
    cin>>n>>m;
    vector<ll> l(n), r(n);
    rep(i, n)cin>>l[i]>>r[i];
    rep(i, n)l[i]--, r[i]--;
    vector<pll> z;
    rep(i, n)z.push_back(pll(r[i], l[i]));
    sort(z.begin(), z.end());
    vector<pll> p;
    z.push_back(pll(inf, inf));
    rep(i, n){
        if(z[i].fst!=z[i+1].fst)p.push_back(z[i]);
    }
    rep(i, p.size())cout<<p[i].fst<<" "<<p[i].snd<<endl;
    ll tl=0, tr=0, now=0, cnt=0;
    rep(i, p.size()){
        cnt+=(p[i].fst-tl+1)*(p[i].fst-tl)/2;
        coc(cnt);
        tl=p[i].snd+1;
        cnt-=(p[i].fst-tl+1)*(p[i].fst-tl)/2;
        coc(cnt)
        if(i==0)continue;
    }
    cnt+=(m-tl+1)*(m-tl)/2;
    cout<<cnt<<endl;
}