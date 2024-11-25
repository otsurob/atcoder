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
    vector<string> c(h);
    cinv(c, h);
    vector<vector<ll>> d={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<pll> ans;
    rep(i, h){
        rep(j, w){
            if(c[i][j]=='S'){
                rep(k, 4){
                    ll ty=i+d[k][0], tx=j+d[k][1];
                    if(ty>=0 and ty<h and tx>=0 and tx<w and c[ty][tx]!='#')ans.push_back(pll(ty, tx));
                }
                c[i][j]='#';
            }
        }
    }
    if(ans.size()==0){
        coutn()
        return 0;
    }
    vector<vector<bool>> seen(h, vector<bool>(w));
    rep(i, ans.size()){
        ll y=ans[i].fst, x=ans[i].snd;
        if(seen[y][x]){
            couty()
            return 0;
        }
        queue<pll> q;
        q.push(pll(y, x));
        while(!q.empty()){
            ll b=q.front().fst, a=q.front().snd;
            q.pop();
            rep(j, 4){
                ll ny=b+d[j][0], nx=a+d[j][1];
                if(ny>=0 and ny<h and nx>=0 and nx<w and c[ny][nx]!='#' and !seen[ny][nx]){
                    q.push(pll(ny, nx));
                    seen[ny][nx]=true;
                }

            }
        }
    }
    coutn()
}