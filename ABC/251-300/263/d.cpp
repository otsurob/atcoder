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
    ll n, l, r;
    cin>>n>>l>>r;
    vector<ll> a(n);
    cinv(a, n);
    vector<ll> sum(n);
    sum[0]=a[0];
    rep2(1, i, n)sum[i]=sum[i-1]+a[i];
    ll mn=n*l;
    ll ps=0, sps=0, ns=0;
    rep(i, n){
        ll d=a[i]-l;
        if(d>=0 and ps+d+sps>=0){
            ps+=d+sps;
            // ps+=d;
            sps=0;
            ns=l*(i+1);
        }
        else{
            ns+=a[i];
            sps+=d;
        }
        mn=min(mn, ns+(n-i-1)*r);
        // coc3(ps, ns, mn);
    }
    cout<<mn<<endl;
}