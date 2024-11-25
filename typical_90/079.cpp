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
    ll h, w;
    cin>>h>>w;
    vector<vector<ll>> a(h, vector<ll>(w)), b(h, vector<ll>(w));
    rep(i, h)rep(j, w)cin>>a[i][j];
    rep(i, h)rep(j, w)cin>>b[i][j];
    ll cnt=0;
    rep(i, h-1){
        rep(j, w-1){
            ll d=b[i][j]-a[i][j];
            a[i][j]+=d;
            a[i+1][j]+=d;
            a[i][j+1]+=d;
            a[i+1][j+1]+=d;
            cnt+=abs(d);
        }
        if(a[i][w-1]!=b[i][w-1]){
            coutn()
            return 0;
        }
    }
    rep(j, w){
        if(a[h-1][j]!=b[h-1][j]){
            coutn()
            return 0;
        }
    }
    couty()
    cout<<cnt<<endl;
}