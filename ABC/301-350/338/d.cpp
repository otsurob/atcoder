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
    ll n, m;
    cin>>n>>m;
    vector<ll> x(m);
    cinv(x, m);
    rep(i, m)x[i]--;
    vector<ll> cnt(n, 0);
    ll ans=0;
    rep2(1, i, m){
        ll a=min(x[i], x[i-1]), b=max(x[i], x[i-1]);
        ll c=abs(x[i]-x[i-1]), d=n-c;
        if(c<d){
            cnt[a]+=d-c;
            cnt[b]-=d-c;
        }else{
            cnt[0]+=c-d;
            cnt[a]-=c-d;
            cnt[b]+=c-d;
            // cnt[n-1]-=c-d;
        }
        ans+=min(c, d);
    }
    rep2(1, i, n)cnt[i]+=cnt[i-1];
    ll mn=cnt[0];
    rep(i, n)mn=min(mn, cnt[i]);
    cout<<ans+mn<<endl;
}