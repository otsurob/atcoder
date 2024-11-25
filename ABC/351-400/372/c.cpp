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
    ll n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<ll> x(q);
    vector<char> c(q);
    rep(i, q)cin>>x[i]>>c[i];
    rep(i, q)x[i]--;
    ll cnt=0;
    rep(i, n-2){
        string t = s.substr(i, 3);
        if(t=="ABC")cnt++;
    }
    rep(i, q){
        string ts = s.substr(max(0ll, x[i]-2), min(5ll, n-x[i]+3));
        s[x[i]]=c[i];
        string ss = s.substr(max(0ll, x[i]-2), min(5ll, n-x[i]+3));
        ll tsc=0, ssc=0;
        rep(j, ts.length()-2){
            if(ts.substr(j, 3)=="ABC")tsc++;
            if(ss.substr(j, 3)=="ABC")ssc++;
        }
        // coc2(ts, ss)
        cnt+=(ssc-tsc);
        cout<<cnt<<endl;
    }
}