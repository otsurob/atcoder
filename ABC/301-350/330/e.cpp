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
    ll n, q;
    cin>>n>>q;
    vector<ll>a(n);
    cinv(a, n);
    vector<ll> l(q), x(q);
    rep(i, q)cin>>l[i]>>x[i];
    rep(i, q)l[i]--;
    vector<ll> cnt(n+1, 0);
    rep(i, n)if(a[i]<=n)cnt[a[i]]++;
    set<ll> st;
    rep(i, n+1)if(cnt[i]==0)st.insert(i);
    rep(i, q){
        // cout<<a[l[i]]<<endl;
        if(a[l[i]]<=n){
            cnt[a[l[i]]]--;
            if(cnt[a[l[i]]]==0)st.insert(a[l[i]]);
        }
        a[l[i]]=x[i];
        // cout<<x[i]<<endl;
        if(x[i]<=n){
            if(cnt[x[i]]==0)st.erase(x[i]);
            cnt[x[i]]++;
        }
        // rep(j, n)cout<<a[j]<<" ";
        // cout<<endl;
        // rep(j, 6)cout<<cnt[j]<<" ";
        // cout<<endl;
        auto it=st.begin();
        cout<<*it<<endl;
    }
}