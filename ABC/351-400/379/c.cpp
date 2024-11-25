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
    vector<ll> x(m), a(m);
    cinv(x, m);
    rep(i, m)x[i]--;
    cinv(a, m);
    vector<pll> z;
    rep(i, m)z.push_back(pll(x[i], a[i]));
    sort(z.begin(), z.end());
    if(x[0]!=0){
        cout<<-1<<endl;
        return 0;
    }
    ll s=z[0].snd;
    ll ans=0, d;
    rep2(1, i, m){
        d=z[i].fst-z[i-1].fst;
        // coc2(s, d);
        if(s<d){
            cout<<-1<<endl;
            return 0;
        }
        ans+=((s-1+s-d)*d)/2;
        s-=d;
        s+=z[i].snd;
    }
    d=n-z[m-1].fst-1;
    // coc2(s, d);
    ans+=((s-1+s-d)*d)/2;
    s-=d;
    if(s!=1){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
}