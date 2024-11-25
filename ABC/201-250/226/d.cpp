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

ull gcd(ull x, ull y){
    if(y==0) return x;
    else return gcd(y, x%y);
}


int main(){
    ll n;
    cin>>n;
    vector<ll> x(n), y(n);
    rep(i, n) cin>>x[i]>>y[i];
    set<pll> st;
    rep(i, n)rep(j, n){
        if(i==j) continue;
        ll xx=x[i]-x[j], yy=y[i]-y[j];
        if(xx==0) yy/=abs(yy);
        else if(yy==0) xx/=abs(xx);
        else{
            ll g =gcd(abs(xx), abs(yy));
            xx/=g, yy/=g;
        }
        st.insert(pll(xx, yy));
    }
    cout<<st.size()<<endl;
}