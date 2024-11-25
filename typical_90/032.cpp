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
    ll n;
    cin>>n;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, n)rep(j, n)cin>>a[i][j];
    ll m;
    cin>>m;
    vector<ll> x(m), y(m);
    rep(i, m)cin>>x[i]>>y[i];
    rep(i, m)x[i]--, y[i]--;
    set<pll> st;
    rep(i, m)st.insert(pll(x[i], y[i]));
    rep(i, m)st.insert(pll(y[i], x[i]));
    vector<ll> p(n);
    rep(i, n)p[i]=i;
    ll inf=99999999999999;
    ll mn=inf;
    do{
        bool flag=false;
        rep(i, n-1){
            if(st.find(pll(p[i], p[i+1]))!=st.end())flag=true;
        }
        if(flag)continue;
        ll now=0;
        rep(i, n)now+=a[p[i]][i];
        mn=min(mn, now);
    }while(next_permutation(p.begin(), p.end()));
    if(mn==inf)cout<<-1<<endl;
    else cout<<mn<<endl;
}