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
    vector<string> s(n);
    cinv(s, n);
    vector<vector<bool>> seen(n, vector<bool>(m, false)), stop(n, vector<bool>(m, false));
    queue<pll> q;
    q.push(pll(1, 1));
    seen[1][1]=true;
    stop[1][1]=true;
    vector<vector<ll>> d={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty()){
        ll y=q.front().fst;
        ll x=q.front().snd;
        q.pop();
        rep(i, 4){
            ll tx=x, ty=y;
            while(s[ty][tx]=='.'){
                seen[ty][tx]=true;
                ty+=d[i][0];
                tx+=d[i][1];
            }
            ty-=d[i][0];
            tx-=d[i][1];
            if(!stop[ty][tx]){
                q.push(pll(ty, tx));
                // coc2(ty, tx)
                stop[ty][tx]=true;
            }
        }
    }
    ll ans=0;
    rep(i, n)rep(j, m)if(seen[i][j]) ans++;
    cout<<ans<<endl;
}