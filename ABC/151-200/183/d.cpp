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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    ll n, w;
    cin>>n>>w;
    vector<ll> s(n), t(n), p(n);
    ll mx=0;
    rep(i, n){
        cin>>s[i]>>t[i]>>p[i];
        mx=max(mx, t[i]);
    }
    vector<ll> v(mx);
    rep(i, n){
        v[s[i]]+=p[i];
        v[t[i]]-=p[i];
    }
    ll now=0;
    rep(i, mx){
        now+=v[i];
        if(now>w){
            coutn();
            return 0;
        }
    }
    couty();

}