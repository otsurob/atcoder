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
#define pll pair<ll, ll>
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    ll n, m, l, q;
    cin>>n;
    vector<ll> a(n);
    cinv(a, n);
    cin>>m;
    vector<ll> b(m);
    cinv(b, m);
    cin>>l;
    vector<ll> c(l);
    cinv(c, l);
    cin>>q;
    vector<ll> x(q);
    cinv(x, q);
    vector<bool> ans(1000000000, false);
    ll p;
    rep(i, n)rep(j, m)rep(k, l){
        p=a[i]+b[j]+c[k];
        ans[p]=true;
    }
    rep(i, q){
        if(ans[x[i]]) {couty()}
        else coutn()
    }
}