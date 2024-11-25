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
    ll mx=1000009;
    ll n;
    cin>>n;
    vector<ll> a(n);
    cinv(a, n);
    vector<ll> s(mx, 0);
    ll sm=0;
    rep(i, n){
        sm+=a[i];
        s[a[i]]+=a[i];
    }
    rep2(1, i, mx) s[i]+=s[i-1];
    rep(i, n){
        cout<<sm-s[a[i]]<<" ";
    }
    cout<<endl;
}