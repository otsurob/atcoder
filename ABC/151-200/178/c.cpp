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
    ll mod=1e9+7;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    ll a=1;
    ll b=1;
    ll al=1;
    rep(i, n){
        a=(a*8)%mod;
        al=(al*10)%mod;
        b=(b*9)%mod;
    }
    // al=(al*10)%mod; 
    b=(al-b)%mod;
    ll ans=(a+b+b-al)%mod;
    if(ans<0) ans+=mod;
    // cout<<a<<b<<al<<endl;
    cout<<ans<<endl;
}