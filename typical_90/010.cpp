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
#define coc(a) cout<<a<<endl;
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
    vector<ll> s1(n+1, 0), s2(n+1, 0);
    vector<ll> c(n), p(n);
    rep(i, n) cin>>c[i]>>p[i];
    ll q;
    cin>>q;
    vector<ll> l(q), r(q);
    rep(j, q){
        cin>>l[j]>>r[j];
    }
    rep(i, n){
        if(c[i]==1){
            s1[i+1]+=s1[i]+p[i];
            s2[i+1]+=s2[i];
        }else{
            s1[i+1]+=s1[i];
            s2[i+1]+=s2[i]+p[i]; 
        }
    }
    vector<pll> ans;
    rep(i, q){
        ans.push_back(pll(s1[r[i]]-s1[l[i]-1], s2[r[i]]-s2[l[i]-1]));
    }
    rep(i, q) coc2(ans[i].fst, ans[i].snd);
}