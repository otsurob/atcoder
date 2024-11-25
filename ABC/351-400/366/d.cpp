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
    cin>>n;
    vector<vector<vector<ll>>> a(n, vector<vector<ll>>(n, vector<ll>(n)));
    rep(i, n)rep(j, n)rep(k, n)cin>>a[i][j][k];
    vector<vector<vector<ll>>> s(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1, 0)));
    rep2(1, i, n+1){
        rep2(1, j, n+1){
            rep2(1, k, n+1){
                s[i][j][k]=s[i][j][k-1]+a[i-1][j-1][k-1];
            }
        }
    }
    rep2(1, i, n+1){
        rep2(1, k, n+1){
            rep2(1, j, n+1){
                s[i][j][k]+=s[i][j-1][k];
            }
        }
    }
    rep2(1, j, n+1){
        rep2(1, k, n+1){
            rep2(1, i, n+1){
                s[i][j][k]+=s[i-1][j][k];
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
        // cout<<s[rx][ry][rz]<<endl;
        ll now=s[rx][ry][rz]-s[rx][ry][lz]-s[rx][ly][rz]-s[lx][ry][rz]+s[rx][ly][lz]+s[lx][ry][lz]+s[lx][ly][rz]-s[lx][ly][lz];
        // coc4(s[rx][ry][rz], s[rx][ry][lz], s[rx][ly][rz], s[lx][ry][rz])
        // coc4(s[rx][ly][lz], s[lx][ry][lz], s[lx][ly][rz], s[lx][ly][lz])
        ans.push_back(now);
    }
    // rep2(1, i, n+1){
    //     rep2(1, j, n+1){
    //         rep2(1, k, n+1){
    //             cout<<s[i][j][k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    rep(i, ans.size())cout<<ans[i]<<endl;
    // cout<<s[2][2][1]<<endl;
}