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
    vector<ll> a(m), b(m);
    vector<vector<ll>> g(n+1);
    rep(i, m){
        cin>>a[i]>>b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    ll q;
    cin>>q;
    vector<ll> x(q), k(q);
    rep(i, q)cin>>x[i]>>k[i];
    vector<ll> ans;
    queue<pll> ql;
    rep(i, q){
        ll cnt=x[i];
        set<ll> st={};
        st.insert(x[i]);
        ql.push(pll(x[i], 0));
        while(!ql.empty()){
            ll z=ql.front().fst, c=ql.front().snd;
            ql.pop();
            if(c==k[i])continue;
            for(ll y : g[z]){
                if(st.find(y)!=st.end())continue;
                st.insert(y);
                ql.push(pll(y, c+1));
                cnt+=y;
            }
        }
        ans.push_back(cnt);
    }
    rep(i, q)cout<<ans[i]<<endl;
}