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
    vector<ll> a(n-1), b(n-1);
    vector<ll> cnt(n);
    vector<vector<ll>> g(n);
    rep(i, n-1){
        cin>>a[i]>>b[i];
        a[i]--, b[i]--;
        cnt[a[i]]++;
        cnt[b[i]]++;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    vector<ll> v(k);
    cinv(v, k);
    rep(i, k)v[i]--;
    vector<bool> f(n, false);
    rep(i, k)f[v[i]]=true;
    queue<ll> q;
    rep(i, n)if(cnt[i]==1)q.push(i);
    vector<bool> t(n, true);
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        if(f[x])continue;
        t[x]=false;
        for(ll z : g[x]){
            if(!t[z])continue;
            cnt[z]--;
            if(cnt[z]==1){
                q.push(z);
            }
        }
    }
    ll ans=0;
    rep(i, n)if(t[i])ans++;
    cout<<ans<<endl;
}