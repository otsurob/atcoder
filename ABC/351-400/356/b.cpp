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
    vector<ll> a(m);
    cinv(a, m);
    vector<vector<ll>> x(n, vector<ll>(m));
    rep(i, n)rep(j, m)cin>>x[i][j];
    vector<ll> sum(m, 0);
    rep(i, m)rep(j, n)sum[i]+=x[j][i];
    rep(i, m){
        if(sum[i]<a[i]){
            coutn()
            return 0;
        }
    }
    couty()
}