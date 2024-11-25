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


ll modinv(ll a, ll mod) {
	long long b = mod, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= mod;
	if (u < 0) u += mod;
	return u;
}


ll calc(ll m, ll mod){
    ll s = to_string(m).length();
    ll num=1;
    ll ans=0;
    rep2(1, i, s){
        ans = (ans + (num+num*10-1)%mod*(num*9%mod)%mod*modinv(2, mod)%mod*i%mod)%mod;
        // cout<<ans<<endl;
        num=(num*10)%mod;
    }
    m%=mod;
    ans = (ans+((num+m)%mod*(m+mod-num+1)%mod*modinv(2, mod)%mod*s%mod))%mod;
    return ans%mod;
}


int main(){
    ll l, r;
    cin>>l>>r;
    ll mod = 1000000007;
    // cout<<calc(l-1, mod)<<" "<<calc(r, mod)<<endl;
    ll ans = (calc(r, mod)+mod-calc(l-1, mod))%mod;
    cout<<ans<<endl;
}