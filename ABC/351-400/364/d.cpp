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
    ll n, q;
    cin>>n>>q;
    vector<ll> a(n);
    cinv(a, n);
    sort(a.begin(), a.end());
    vector<ll> b(q), k(q);
    rep(i, q)cin>>b[i]>>k[i];
    vector<vector<ll>> bk;
    rep(i, q)bk.push_back({b[i], k[i], i});
    sort(bk.begin(), bk.end());
    vector<ll> v1;
    deque<ll> v2;
    rep(i, n)v2.push_back(a[i]);
    vector<ll> ans(q);
    rep(i, q){
        ll l=-1, r=9999999999;
        while(!v2.empty() and v2.front()<bk[i][0]){
            ll x=v2.front();
            v1.push_back(x);
            v2.pop_front();
        }
        ll a=bk[i][0];
        while(l+1!=r){
            ll m=(l+r)/2;
            ll it1 = lower_bound(v1.begin(), v1.end(), a-m)-v1.begin();
            ll it2 = upper_bound(v2.begin(), v2.end(), a+m)-v2.begin();
            ll s=(v1.size()-it1)+it2;
            // coc3(m, v1.size()-it1, it2)
            if(s<bk[i][1]){
                l=m;
            }
            else{
                r=m;
            }
        }
        ans[bk[i][2]]=r;
    }
    rep(i, q)cout<<ans[i]<<endl;
}