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
    vector<string> a(h);
    cinv(a, h);
    pll sta, gl;
    map<char, pll> mv;
    map<char, vector<pll>> loc;
    vector<vector<ll>> d={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    string dir="v^><";
    rep(i, h){
        rep(j, w){
            if(a[i][j]=='S')sta=pll(i, j), a[i][j]='.';
            if(a[i][j]=='G')gl=pll(i, j), a[i][j]='.';
            rep(k, 4){
                if(a[i][j]==dir[k])loc[a[i][j]].push_back(pll(i, j));
            }
        }
    }
    rep(i, 4){
        rep(j, loc[dir[i]].size()){
            ll ny=loc[dir[i]][j].fst+d[i][0], nx=loc[dir[i]][j].snd+d[i][1];
            while(ny>=0 and ny<h and nx>=0 and nx<w and (a[ny][nx]=='.' or a[ny][nx]=='x')){
                a[ny][nx]='x';
                ny+=d[i][0], nx+=d[i][1];
            }
        }
    }
    vector<vector<ll>> seen(h, vector<ll>(w, -1));
    queue<pll> q;
    q.push(sta);
    seen[sta.fst][sta.snd]=0;
    while(!q.empty()){
        ll y=q.front().fst, x=q.front().snd;
        q.pop();
        if(pll(y, x)==gl){
            cout<<seen[y][x]<<endl;
            return 0;
        }
        rep(i, 4){
            ll ny=y+d[i][0], nx=x+d[i][1];
            if(ny>=0 and ny<h and nx>=0 and nx<w and a[ny][nx]=='.' and seen[ny][nx]==-1){
                seen[ny][nx]=seen[y][x]+1;
                q.push(pll(ny, nx));
            }
        }
    }
    cout<<-1<<endl;
}