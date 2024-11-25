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
int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll> seen(100000, -1);
    seen[n]=0;
    ll m=-1, nx=-1, ans=n;
    rep(i, k){
        ll now=0;
        ll tmp=n;
        rep(j, 6){
            now+=tmp%10;
            tmp/=10;
        }
        nx=now+n;
        nx%=100000;
        if(seen[nx]!=-1){
            ll lp=i+1-seen[nx];
            m=((k-seen[nx])/lp)*lp+seen[nx];
            // coc2(nx, n)
            // coc3(seen[nx], i+1, m)
            n=nx;
            ans=n;
            break;
        }
        seen[nx]=i+1;
        n=nx;
        // coc3(now, nx, n);
    }
    if(m==-1){
        cout<<nx<<endl;
        return 0;
    }
    rep2(m, i, k){
        ll now=0;
        ll tmp=n;
        rep(j, 6){
            now+=tmp%10;
            tmp/=10;
        }
        ans=now+n;
        ans%=100000;
        n=ans;
    }
    cout<<ans<<endl;
}