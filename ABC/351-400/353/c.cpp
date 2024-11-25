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
    vector<ll> a(n);
    cinv(a, n);
    ll m=100000000;
    sort(a.begin(), a.end());
    ll sum=0;
    rep(i, n)sum+=a[i];
    ll ans=0;
    ll l=0, r=n-1;
    ll num=n-1;
    ll te=0;
    rep(i, n-1){
        while(i<r and a[i]+a[r]>=m)r--;
        if(r<i)r=i;
        ans+=sum+(a[i]*(num-1));
        // te+=(n-1-r)*m;
        ans-=(n-1-r)*m;
        sum-=a[i];
        num--;
    }
    // cout<<te<<endl;
    cout<<ans<<endl;
}