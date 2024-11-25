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
    rep(i, n){
        cin>>l[i]>>r[i];
    }
    ll mn=0, mx=0;
    rep(i, n){
        mn+=l[i];
        mx+=r[i];
    }
    vector<ll> ans(n);
    if(mn<=0 and mx>=0){
        couty()
        rep(i, n)ans[i]=l[i];
        rep(i, n){
            ans[i]+=min(0-mn, r[i]-l[i]);
            mn+=min(0-mn, r[i]-l[i]);
        }
        rep(i, n)cout<<ans[i]<<" ";
        cout<<endl;
    }
    else coutn()
}