#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<' ';
#define codl() cout<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
#define decout(a) cout<<fixed<<setprecision(15)<<a<<endl;
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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
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
int main(){
    ll mod=998244353;
    ll n;
    cin>>n;
    ll ans=0;
    ll dg=0;
    ll m=n;
    while(m>0){
        dg++;
        m/=10;
    }
    ll x=powl(10, dg-1);
    x%=mod;
    // coc(x)
    ll mi=modinv(2, mod);
    x=(x+mod-1)%mod;
    ll now=1;
    rep(i, dg-1){
        ans += ((1+now*9)%mod*(now*9%mod))%mod*mi%mod;
        // coc2(((1+now*9)%mod*(now%mod))%mod*mi%mod, i)
        now=now*10%mod;
    }
    // coc(ans)
    ll z=n-x;
    // coc(z)
    ans += ((1+z)%mod*(z%mod))%mod*mi%mod;
    cout<<ans%mod<<endl;
}