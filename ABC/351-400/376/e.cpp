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
    ll t, n, k;
    cin>>t;
    vector<ll> res;
    vector<ll> a, b;
    rep(q, t){
        a={}, b={};
        cin>>n>>k;
        a.resize(n), b.resize(n);
        cinv(a, n);
        cinv(b, n);
        ll ans=inf, sum=0;
        vector<pll> p={};
        rep(i, n)p.push_back(pll(a[i], b[i]));
        sort(p.begin(), p.end());
        priority_queue<ll> pq;
        rep(i, n){
            if(pq.size()==k-1){
                chmin(ans, (sum+p[i].snd)*p[i].fst);
            }
            pq.push(p[i].snd);
            sum+=p[i].snd;
            if(pq.size()>=k){
                sum-=pq.top();
                pq.pop();
            }
        }
        res.push_back(ans);
    }
    rep(i, t)cout<<res[i]<<endl;
}