#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<' ';
#define codl() cout<<endl;
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
#define inf 999999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }


ll h, w, k;
vector<string> s;
vector<vector<bool>> seen;
ll ans=0;
vector<vector<ll>> d={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(ll x, ll y, ll c){
    if(c==k){
        ans++;
        return;
    }
    rep(p, 4){
        ll ny=y+d[p][0], nx=x+d[p][1];
        if(ny<0 or ny>=h or nx<0 or nx>=w or s[ny][nx]=='#' or seen[ny][nx])continue;
        seen[ny][nx]=true;
        dfs(nx, ny, c+1);
        seen[ny][nx]=false;
    }
}



int main(){
    cin>>h>>w>>k;
    s.resize(h);
    cinv(s, h);
    seen.resize(h);
    rep(i, h)seen[i].resize(w, false);
    rep(i, h)rep(j, w){
        if(s[i][j]=='#')continue;
        rep(a, h)rep(b, w)seen[a][b]=false;
        seen[i][j]=true;
        dfs(j, i, 0);
    }
    cout<<ans<<endl;
}