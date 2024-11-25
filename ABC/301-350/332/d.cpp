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
    ll h, w;
    cin>>h>>w;
    vector<vector<ll>> a(h, vector<ll>(w)), b(h, vector<ll>(w));
    rep(j, h)cinv(a[j], w);
    rep(j, h)cinv(b[j], w);
    vector<ll> ph, pw;
    rep(i, h)ph.push_back(i);
    rep(i, w)pw.push_back(i);
    vector<vector<ll>> t, tt;
    // vector<ll> ansh={}, answ={};
    ll inf=9999999999;
    ll mn=inf;
    do{
        do{
            t=a;
            // bool f=false;
            rep(i, h)rep(j, w)t[i][j]=a[i][pw[j]];
            tt=t;
            rep(j, w)rep(i, h)t[i][j]=tt[ph[i]][j];
            if(t==b){
                // f=true;
                // ansh=ph, answ=pw;
                ll cnt=0;
                rep(i, h-1)rep2(i+1, j, h)if(ph[i]>ph[j])cnt++;
                rep(i, w-1)rep2(i+1, j, w)if(pw[i]>pw[j])cnt++;
                chmin(mn, cnt);
            }
        }while(next_permutation(pw.begin(), pw.end()));
    }while(next_permutation(ph.begin(), ph.end()));
    if(mn==inf){
        cout<<-1<<endl;
        return 0;
    }
    cout<<mn<<endl;
}