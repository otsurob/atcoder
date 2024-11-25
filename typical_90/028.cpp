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
    vector<ll> lx(n), ly(n), rx(n), ry(n);
    vector<vector<ll>> g(1002, vector<ll>(1002, 0));
    vector<ll> ans(n+1, 0);
    rep(i, n){
        cin>>lx[i]>>ly[i]>>rx[i]>>ry[i];
        // lx[i]--, ly[i]--, rx[i]--, ry[i]--;
        g[ly[i]][lx[i]]++;
        g[ly[i]][rx[i]]--;
        g[ry[i]][lx[i]]--;
        g[ry[i]][rx[i]]++;
    }
    // rep(i, 10){
    //     rep(j, 10){
    //         cout<<g[i][j];
    //     }
    //     cout<<endl;
    // }
    rep(i, 1002)rep2(1, j, 1002)g[i][j]+=g[i][j-1];
    rep(j, 1002)rep2(1, i, 1002)g[i][j]+=g[i-1][j];
    // cout<<endl;
    // rep(i, 10){
    //     rep(j, 10){
    //         cout<<g[i][j];
    //     }
    //     cout<<endl;
    // }
    rep(i, 1002)rep(j, 1002)ans[g[i][j]]++;
    rep2(1, i, n+1)cout<<ans[i]<<endl;
}