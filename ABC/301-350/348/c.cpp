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
    ll n;
    cin>>n;
    vector<ll> a(n), c(n);
    rep(i, n) cin>>a[i]>>c[i];
    vector<pll> s;
    rep(i, n) s.push_back(pll(c[i], a[i]));
    sort(s.begin(), s.end());
    vector<ll> al;
    ll cc=s[0].fst, aa=s[0].snd;
    al.push_back(aa);
    // rep(i, n) cout<<s[i].fst<<endl;
    rep2(1, i, n){
        if(s[i].fst!=cc){
            cc=s[i].fst;
            aa=s[i].snd;
            al.push_back(aa);
        }
    }
    ll mx=-1;
    rep(i, al.size()) mx=max(mx, al[i]);
    cout<<mx<<endl;
}