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
    ll n, m;
    cin>>n>>m;
    vector<ll> a(n);
    cinv(a, n);
    ull sum=0;
    rep(i, n)sum+=a[i];
    if(sum<=m){
        cout<<"infinite"<<endl;
        return 0;
    }
    sort(a.begin(), a.end());
    vector<ll> s(n+1);
    s[0]=0;
    rep(i, n)s[i+1]=s[i]+a[i];
    a.push_back(99999999999999999);
    ll l=0, r=9999999999999999, mid=(l+r)/2;
    while(l+1<r){
        mid=(l+r)/2;
        ll it = lower_bound(a.begin(), a.end(), mid) - a.begin();
        ll sum=s[it] + (n-it)*mid;
        // coc4(mid, sum, it, s[it]);
        if(sum<=m)l=mid;
        else r=mid;
    }
    cout<<l<<endl;
}