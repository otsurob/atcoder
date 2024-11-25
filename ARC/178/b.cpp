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

ll mod=998244353;


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

ll g=modinv(2, mod);

ll modpow(ll x, ll n) {
  x = x%mod;
  if(n==0) return 1;  //再帰の終了条件

  else if(n%2==1) {
    return (x*modpow(x, n-1))%mod;  //nが奇数ならnを1ずらす
  }
  else return modpow((x*x)%mod, (n*g)%mod)%mod;  //nが偶数ならnが半分になる
}



int main(){
    ll t;
    cin>>t;
    vector<ll> ans;
    rep(i, t){
        ll a, b, c;
        cin>>a>>b>>c;
        if(a>b)swap(a, b);
        ll d=c-b;
        if(d!=0 and d!=1){
            ans.push_back(0);
            continue;
        }
        if(a==1 and b==1){
            if(d==0){
                ans.push_back(36);
                continue;
            }
            if(d==1){
                ans.push_back(45);
                continue;
            }
        }
        // wow()
        ll z1=modpow(10, a-1)%mod;
        ll z2=modpow(10, a)%mod;
        ll z3=((z1+z2-1+mod)%mod)*9*z1%mod;
        ll z=z3*g%mod;
        ll y1=9*z1%mod;
        ll y2=y1*z1%mod;
        ll y3=((y1-1+z1+mod)%mod)*8*z1%mod;
        ll y4=y3*g%mod;
        ll y=y2+y4%mod;
        ll al=81*z1*z1%mod;
        // coc3(al, z, y)
        if(d==1){
            if(a!=b){
                ans.push_back(z);
            }
            else{
                ans.push_back(y);
            }
        }
        if(d==0){
            if(a!=b){
                ans.push_back((al+mod-z)%mod);
            }
            else{
                ans.push_back((al+mod-y)%mod);
            }
        }
    }
    rep(i, t)cout<<ans[i]<<endl;
}