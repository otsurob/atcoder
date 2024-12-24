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
#define inf 999999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    cinv(a, n);
    vector<ll> b=a;
    sort(b.begin(), b.end());
    ll cnt=0;
    ll m=0;
    // rep(i, n)if(a[i]!=0)m++;
    m=n;
    ll bn=0;
    while(true){
        if(k==0)break;
        ll c=b[bn]-cnt;
        if(c==0){
            m--;
            bn++;
            continue;
        }
        if(k>m*c){
            k-=m*c;
            cnt+=c;
        }else{
            ll x=k/m;
            k-=x*m;
            cnt+=x;
            break;
        }
    }
    vector<ll> ans=a;
    rep(i, n)ans[i]=max(0ll, ans[i]-cnt);
    rep(i, n){
        if(k==0)break;
        if(ans[i]!=0){
            ans[i]--;
            k--;
        }
    }
    coutv(ans, n);
    codl();
}