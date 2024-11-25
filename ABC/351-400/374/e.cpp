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
    ll n, x;
    cin>>n>>x;
    vector<ll> a(n), p(n), b(n), q(n);
    rep(i, n)cin>>a[i]>>p[i]>>b[i]>>q[i];
    ll l=-1, r=9999999999;
    ll ans=0;
    while(l+1!=r){
        ll m=(l+r)/2;
        ll cs=0, ps=0, nc=0;;
        rep(i, n){
            ll mn=999999999999999;
            rep(j, a[i]+1){
                nc=q[i]*j;
                ll mt=max(0ll, m-(b[i]*j));
                ll sn;
                if(mt%a[i]==0)sn=mt/a[i];
                else sn=(mt/a[i])+1;
                nc+=sn*p[i];
                chmin(mn, nc);
            }
            rep(j, b[i]+1){
                nc=p[i]*j;
                ll mt=max(0ll, m-(a[i]*j));
                ll sn;
                if(mt%b[i]==0)sn=mt/b[i];
                else sn=(mt/b[i])+1;
                nc+=sn*q[i];
                chmin(mn, nc);
            }
            cs+=mn;
        }
        if(cs>x){
            r=m;
        }else{
            l=m;
        }
    }
    cout<<l<<endl;
}