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
    int n;
    cin>>n;
    ll smx=0, smy=0;
    ll x, y;
    rep(i, n){
        cin>>x>>y;
        smx+=x;
        smy+=y;
    }
    // cout<<smx<<smy<<endl;
    if(smx>smy) cout<<"Takahashi"<<endl;
    else if(smx<smy) cout<<"Aoki"<<endl;
    else cout<<"Draw"<<endl;
}