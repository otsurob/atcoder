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


ll repeat_pow(ll a, ll n, ll mod) {
    if (n == 0) return 1;
    if (n == 1) return a % mod;

    ll ret = repeat_pow(a, n / 2, mod) % mod;
    (ret *= ret) %= mod;
    if (n % 2 == 1) {
        (ret *= a) %= mod;
    }
    return ret%mod;
}



int main(){
    ll n, k;
    cin>>n>>k;
    ll mod=1000000007;
    if(n<3){
        if(n==1)cout<<k<<endl;
        else if(n==2){
            ll ans=(k*(k-1))%mod;
            cout<<ans<<endl;
        }
    }
    else if(k<3){
        cout<<0<<endl;
    }
    else{
        ll ans=0;
        ans=(k%mod)*((k-1)%mod)%mod*repeat_pow(k-2, n-2, mod)%mod;
        cout<<ans%mod<<endl;
    }
}