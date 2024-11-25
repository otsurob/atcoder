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
int main(){
    ll n, s, t;
    cin>>n>>s>>t;
    vector<ll> a(n), b(n), c(n), d(n);
    rep(i, n)cin>>a[i]>>b[i]>>c[i]>>d[i];
    ld sum=999999999999999;
    // ll ts=1;
    // rep2(1, i, 13)ts*=i;
    // cout<<ts<<endl;
    vector<ll> p;
    rep(i, n)p.push_back(i);
    ll x=0, y=0;
    ld ans=0;
    do{
        rep(i, 1<<n){
            ans=0;
            x=0, y=0;
            rep(j, n){
                ll wari = 1<<j;
                if((i/wari)%2==0){
                    ans+=sqrt(abs(x-a[p[j]])*abs(x-a[p[j]])+abs(y-b[p[j]])*abs(y-b[p[j]]))/s;
                    x=c[p[j]], y=d[p[j]];
                }
                else{
                    ans+=sqrt(abs(x-c[p[j]])*abs(x-c[p[j]])+abs(y-d[p[j]])*abs(y-d[p[j]]))/s;
                    x=a[p[j]], y=b[p[j]];
                }
                ans+=sqrt(abs(c[p[j]]-a[p[j]])*abs(c[p[j]]-a[p[j]])+abs(d[p[j]]-b[p[j]])*abs(d[p[j]]-b[p[j]]))/t;
                
            }
            sum=min(sum, ans);
        }
    }while(next_permutation(p.begin(), p.end()));
    decout(sum);
}