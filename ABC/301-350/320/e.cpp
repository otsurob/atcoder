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
    vector<ll> t(m), w(m), s(m);
    rep(i, m){
        cin>>t[i]>>w[i]>>s[i];
    }
    set<ll> st;
    set<pll> tm;
    rep(i, n)st.insert(i+1);
    vector<ll> sum(n+1, 0);
    rep(i, m){
        while(!tm.empty()){
            auto it=tm.begin();
            pll x = *it;
            if(x.fst>t[i])break;
            st.insert(x.snd);
            tm.erase(x);
        }
        if(st.empty())continue;
        auto it2=st.begin();
        ll y=*it2;
        sum[y]+=w[i];
        tm.insert(pll(t[i]+s[i], y));
        st.erase(y);
    }
    rep2(1, i, n+1)cout<<sum[i]<<endl;
}