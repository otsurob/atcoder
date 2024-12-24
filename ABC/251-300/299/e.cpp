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
    ll n, m;
    cin>>n>>m;
    vector<ll> u(m), v(m);
    vector<vector<ll>> g(n);
    rep(i, m){
        cin>>u[i]>>v[i];
        u[i]--, v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    ll k;
    cin>>k;
    vector<ll> p(k), d(k);
    rep(i, k){
        cin>>p[i]>>d[i];
        p[i]--;
    }
    vector<vector<ll>> a(n, vector<ll>(n, 0));
    vector<ll> ans(n, 0);
    queue<pll> q;
    rep(i, n){
        vector<bool> seen(n, false);
        seen[i]=true;
        q.push(pll(i, 0));
        while(!q.empty()){
            ll x=q.front().fst, c=q.front().snd;
            q.pop();
            for(ll z: g[x]){
                if(!seen[z]){
                    seen[z]=true;
                    q.push(pll(z, c+1));
                    a[i][z]=c+1;
                }
            }
        }
    }
    // rep(i, n){
    //     rep(j, n){
    //         cout<<a[i][j]<<" ";
    //     }
    //     codl();
    // }
    rep(i, k){
        rep(j, n){
            if(a[p[i]][j]<d[i]){
                ans[j]=1;
            }
        }
    }
    // coutv(ans, n);
    // codl()
    rep(i, k){
        bool f=false;
        rep(j, n){
            if(a[p[i]][j]==d[i] and ans[j]!=1){
                ans[j]=2;
                f=true;
            }
        }
        if(!f){
            coutn()
            return 0;
        }
    }
    couty()
    rep(i, n){
        if(ans[i]==1)cout<<0;
        else cout<<1;
    }
    codl();
}