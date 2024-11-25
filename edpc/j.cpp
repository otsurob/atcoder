#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
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
    ll n;
    cin>>n;
    // ll mod=1000000007;
    vector<ll> a(n);
    cinv(a, n);
    vector<vector<vector<ld>>> dp(n+1, vector<vector<ld>>(n+1, vector<ld>(n+1, 0)));
    ll c1=0, c2=0, c3=0;
    rep(i, n){
        if(a[i]==1)c1++;
        if(a[i]==2)c2++;
        if(a[i]==3)c3++;
    }
    // ll m=modinv(n, mod);
    dp[c3][c2][c1]=0;
    if(c3!=0)dp[c3-1][c2+1][c1]+=(dp[c3][c2][c1]+1)*(ld)c3/n;
    if(c2!=0)dp[c3][c2-1][c1+1]+=(dp[c3][c2][c1]+1)*(ld)c2/n;
    if(c1!=0)dp[c3][c2][c1-1]+=(dp[c3][c2][c1]+1)*(ld)c1/n;
    
    rrep(k, n+1){
        rrep(j, n+1){
            rrep(i, n+1){
                if(dp[i][j][k]!=0){
                    if(i!=0)dp[i-1][j+1][k]+=(dp[i][j][k]+1)*(ld)i/n;
                    if(j!=0)dp[i][j-1][k+1]+=(dp[i][j][k]+1)*(ld)j/n;
                    if(k!=0)dp[i][j][k-1]+=(dp[i][j][k]+1)*(ld)k/n;
                    coc4(dp[i][j][k], i, j, k)
                }
            }
        }
    }
    decout(dp[0][0][0]);
}