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
    ll n, p, q;
    cin>>n>>p>>q;
    vector<ll> a(n);
    cinv(a, n);
    ll ans=0;
    ll cnt=0;
    rep(i, n-4)rep2(i+1, j, n-3)rep2(j+1, k, n-2)rep2(k+1, l, n-1)rep2(l+1, m, n)if((a[i]%p*a[j]%p*a[k]%p*a[l]%p*a[m]%p)%p==q)ans++;
    rep(i, 100-4)rep2(i+1, j, 100-3)rep2(j+1, k, 100-2)rep2(k+1, l, 100-1)rep2(l+1, m, 100)cnt++;
    cout<<ans<<endl;
    cout<<cnt<<endl;
}