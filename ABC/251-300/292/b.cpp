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
    ll n, q;
    cin>>n>>q;
    vector<ll> a(q), b(q);
    rep(i, q) cin>>a[i]>>b[i];
    vector<ll> p(n);
    rep(i, q){
        if(a[i]==1) p[b[i]-1]++;
        else if(a[i]==2) p[b[i]-1]+=2;
        else{
            if(p[b[i]-1]>=2) {couty();}
            else coutn();
        }
    }
}