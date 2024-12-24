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
    ll h, w, n;
    cin>>h>>w>>n;
    vector<ll> a(n), b(n);
    rep(i, n){
        cin>>a[i]>>b[i];
        a[i]--, b[i]--;
    }
    vector<pll> hh, ww;
    rep(i, n){
        hh.push_back(pll(a[i], i));
        ww.push_back(pll(b[i], i));
    }
    sort(hh.begin(), hh.end());
    sort(ww.begin(), ww.end());
    vector<ll> ansh(n), answ(n);
    ansh[hh[0].snd]=1;
    answ[ww[0].snd]=1;
    ll nh=1, nw=1;
    rep2(1, i, n){
        if(hh[i].fst!=hh[i-1].fst)nh++;
        if(ww[i].fst!=ww[i-1].fst)nw++;
        ansh[hh[i].snd]=nh;
        answ[ww[i].snd]=nw;
    }
    rep(i, n)cout<<ansh[i]<<" "<<answ[i]<<endl;
}