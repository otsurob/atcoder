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
    vector<ll> l(n), r(n);
    vector<pll> ans, f;
    rep(i, n){
        cin>>l[i]>>r[i];
        f.push_back(pll(l[i], r[i]));
    }
    sort(f.begin(), f.end());
    ll nl=f[0].fst, nr=f[0].snd;
    rep(i, n){
        if(nr<f[i].fst){
            ans.push_back(pll(nl, nr));
            nl=f[i].fst;
            nr=f[i].snd;
        }
        else{
            nr=max(nr, f[i].snd);
        }
    }
    ans.push_back(pll(nl, nr));
    // sort(ans.rbegin(), ans.rend());
    rep(i, ans.size())coc2(ans[i].fst, ans[i].snd);
}