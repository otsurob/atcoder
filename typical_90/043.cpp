#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
#define decout(a) cout<<fixed<<setprecision(15)<<a<<endl;
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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll inf = 999999999999999;
    // ll inf=100;
    ll h, w;
    cin>>h>>w;
    ll rs, cs, rt, ct;
    cin>>rs>>cs>>rt>>ct;
    rs--, cs--, rt--, ct--;
    vector<string> s(h);
    cinv(s, h);
    vector<vector<vector<ll>>> g(h, vector<vector<ll>>(w, vector<ll>(4, inf)));
    // rep(i, 4)g[rs][cs][i]=0;
    // priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    deque<vector<ll>> pq;
    rep(i, 4)pq.push_back({0, rs, cs, i});
    vector<vector<ll>> d={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while(!pq.empty()){
        // wow()
        ll m = pq.front()[0];
        ll y = pq.front()[1];
        ll x = pq.front()[2];
        ll dir = pq.front()[3];
        pq.pop_front();
        if(g[y][x][dir]<m)continue;
        g[y][x][dir]=m;
        ll ny=y+d[dir][0], nx=x+d[dir][1];
        // coc3(ny, nx, dir)
        if(ny<0 or ny>=h or nx<0 or nx>=w or s[ny][nx]=='#')continue;
        // wow()
        // coc4(m, y, x, dir)
        rep(i, 4){
            if(dir==i and g[ny][nx][i]>m){
                g[ny][nx][i]=m;
                pq.push_front({m, ny, nx, i});
            }
            else if(dir!=i and g[ny][nx][i]>m+1){
                g[ny][nx][i]=m+1;
                pq.push_back({m+1, ny, nx, i});
            
            }
        }
    }
    // rep(i, h){
    //     rep(j, w){
    //         rep(k, 4){
    //             cout<<g[i][j][k];
    //         }
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }
    ll ans=inf;
    rep(i, 4)chmin(ans, g[rt][ct][i]);
    cout<<ans<<endl;
}