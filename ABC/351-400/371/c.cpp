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
    ll n, mg, mh;
    cin>>n>>mg;
    vector<ll> u(mg), v(mg);
    vector<set<ll>> g(n);
    rep(i, mg){
        cin>>u[i]>>v[i];
        u[i]--, v[i]--;
        g[u[i]].insert(v[i]);
        g[v[i]].insert(u[i]);
    }
    cin>>mh;
    vector<ll> a(mh), b(mh);
    vector<set<ll>> h(n);
    rep(i, mh){
        cin>>a[i]>>b[i];
        a[i]--, b[i]--;
        h[a[i]].insert(b[i]);
        h[b[i]].insert(a[i]);
    }
    vector<vector<ll>> c(n, vector<ll>(n, 0));
    rep(i, n-1){
        rep(j, n){
            if(j<=i)continue;
            cin>>c[i][j];
        }
    }
    // rep(i, n){
    //     rep(j, n){
    //         cout<<c[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    ll mn=999999999999999;
    vector<ll> d;
    rep(i, n)d.push_back(i);
    do{
        ll s=0;
        vector<set<ll>> t=h;
        rep(i, n){
            rep(j, n){
                if(g[i].find(j)!=g[i].end() and t[d[i]].find(d[j])==t[d[i]].end()){
                    t[d[i]].insert(d[j]);
                    t[d[j]].insert(d[i]);
                    s+=c[min(d[i], d[j])][max(d[i], d[j])];
                }
                else if(g[i].find(j)==g[i].end() and t[d[i]].find(d[j])!=t[d[i]].end()){
                    t[d[i]].erase(d[j]);
                    t[d[j]].erase(d[i]);
                    s+=c[min(d[i], d[j])][max(d[i], d[j])];
                }
            }
        }
        // rep(k, n)cout<<d[k]<<" ";
        // coc2(mn, s)
        mn=min(mn, s);
    }while(next_permutation(d.begin(), d.end()));
    cout<<mn<<endl;
}