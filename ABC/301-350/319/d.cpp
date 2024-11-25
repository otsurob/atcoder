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
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    cinv(a, n);
    rep(i, n) a[i]++;
    // vector<ll> s(n+1, 0);
    // rep(i, n) s[i+1]=s[i]+a[i]+1;
    ll l=0, r=0;
    rep(i, n) l=max(l, a[i]);
    rep(i, n) r+=a[i];
    l--;
    ll sta=0, now=0, ns=0, cnt=0;
    a.push_back(0);
    while(l+1<r){
        ll mid=(l+r)/2;
        cnt=1;
        ns=0;
        rep(i, n){
            // coc(now)
            // coc3(ns, now, sta)
            ns+=a[i];
            if(ns>mid){
                cnt++;
                ns=a[i];
            }
        }
        if(cnt<=m) r=mid;
        else l=mid;
        // coc3(l, r, mid);
    }
    cout<<r-1<<endl;
}