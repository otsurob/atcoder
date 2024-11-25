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
    ll n;
    cin>>n;
    vector<ll> d(n);
    ll a, b;
    ll s=0;
    rep(i, n){
        cin>>a>>b;
        d[i]=a+a+b;
        s+=a;
    }
    sort(d.rbegin(), d.rend());
    ll t=0;
    rep(i, n){
        t+=d[i];
        if(s<t){
            cout<<i+1<<endl;
            return 0;
        }
    }
}