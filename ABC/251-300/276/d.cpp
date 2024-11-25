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

ull gcd(ull x, ull y){
    if(y==0) return x;
    else return gcd(y, x%y);
}

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    cinv(a, n);
    ll g=a[0];
    rep(i, n){
        g=gcd(g, a[i]);
    }
    ll ans=0;
    rep(i, n){
        a[i]/=g;
        while(a[i]%2==0){
            a[i]/=2;
            ans++;
        }
        while(a[i]%3==0){
            a[i]/=3;
            ans++;
        }
        if(a[i]!=1){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}