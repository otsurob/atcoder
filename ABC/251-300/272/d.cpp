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
    vector<pll> mov;
    for(ll i=0; i*i<=m; i++){
        for(ll j=0; j*j<=m; j++){
            if(i*i+j*j==m)mov.push_back(pll(i, j));
        }
    }
    // rep(i, mov.size())coc2(mov[i].fst, mov[i].snd)
    vector<vector<ll>> d={{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    vector<vector<ll>> ans(n, vector<ll>(n, -1));
    queue<vector<ll>> q;
    q.push({0, 0, 0});
    ans[0][0]=0;
    while(!q.empty()){
        ll y=q.front()[0], x=q.front()[1], z=q.front()[2];
        q.pop();
        rep(i, mov.size()){
            rep(j, 4){
                ll ny=y+mov[i].fst*d[j][0], nx=x+mov[i].snd*d[j][1];
                if(ny>=0 and ny<n and nx>=0 and nx<n and ans[ny][nx]==-1){
                    ans[ny][nx]=z+1;
                    q.push({ny, nx, z+1});
                }
            }
        }
    }
    rep(i, n){
        rep(j, n)cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}