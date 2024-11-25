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


int main(){
    ll q;
    cin>>q;
    vector<ll> ans;
    ll mod=998244353;
    ll k=1, s=1;
    deque<ll> y;
    y.push_back(1);
    ll r=modinv(10, mod);
    // cout<<r<<endl;
    rep(i, q){
        ll que;
        cin>>que;
        if(que==1){
            ll x;
            cin>>x;
            s*=10;
            s+=x;
            s%=mod;
            k*=10;
            k%=mod;
            y.push_back(x);
        }
        else if(que==2){
            ll d=(k*y[0])%mod;
            y.pop_front();
            s=(s+mod-d)%mod;
            // coc2(s, d)
            k=(k*r)%mod;
        }
        else if(que==3){
            ans.push_back(s);
        }
    }
    rep(i, ans.size())cout<<ans[i]<<endl;
}