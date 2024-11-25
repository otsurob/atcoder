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
void chmin(int &a, int b) { a = min(a, b); }
void chmax(int &a, int b) { a = max(a, b); }
int main(){
    ll n;
    cin >> n;
    vector<vector<vector<ll>>> a(n, vector<vector<ll>>(n, vector<ll>(n, 0)));
    rep(i, n)rep(j, n)rep(k, n)cin>>a[i][j][k];
    vector<vector<vector<ll>>> sum(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0LL)));
    rep(i, n){
        rep(j, n){
            rep(k, n){
                sum[i + 1][j + 1][k + 1] =
                    sum[i][j + 1][k + 1] + sum[i + 1][j][k + 1] +
                    sum[i + 1][j + 1][k] - sum[i][j][k + 1] - sum[i][j + 1][k] -
                    sum[i + 1][j][k] + sum[i][j][k] + a[i][j][k];
            }
        }
    }
    ll q;
    cin>>q;
    vector<ll> ans;
    while(q--){
        ll lx, rx, ly, ry, lz, rz;
        cin>>lx>>rx>>ly>>ry>>lz>>rz;
        lx--, ly--, lz--;
        ll now=sum[rx][ry][rz]-sum[rx][ry][lz]-sum[rx][ly][rz]-sum[lx][ry][rz]+sum[rx][ly][lz]+sum[lx][ry][lz]+sum[lx][ly][rz]-sum[lx][ly][lz];
        ans.push_back(now);
    }
    rep(i, ans.size())cout<<ans[i]<<endl;
}