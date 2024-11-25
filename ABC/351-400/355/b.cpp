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
    ll n, m;
    cin>>n>>m;
    vector<ll> a(n), b(m);
    cinv(a, n);
    cinv(b, m);
    vector<pll> c;
    rep(i, n)c.push_back(pll(a[i], 1));
    rep(i, m)c.push_back(pll(b[i], 2));
    // sort(a.begin(), a.end());
    // sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll fl=c[0].snd;
    rep2(1, i, c.size()){
        if(fl==1 and c[i].snd==1){
            couty()
            return 0;
        }
        fl=c[i].snd;
    }
    coutn()
}