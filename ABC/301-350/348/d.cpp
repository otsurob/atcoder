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
    ll n;
    cin>>n;
    vector<ll> r(n), c(n), e(n);
    rep(i, n){
        cin>>r[i]>>c[i]>>e[i];
        r[i]--;
        c[i]--;
    }
    vector<vector<pair<char, ll>>> aa(h, vector<pair<char, ll>>(w));
    rep(i, h)rep(j, w)aa[i][j]=pair<char, ll>(a[i][j], -1);
    pll st, gl;
    rep(i, h)rep(j, w){
        if(a[i][j]=='S'){
            st=pll(i, j);
            aa[i][j].fst='.';
        }
        if(a[i][j]=='T'){
            gl=pll(i, j);
            aa[i][j].fst='.';
        }
    }
    rep(i, n){
        aa[r[i]][c[i]].snd=e[i];
    }
    // rep(i, h) cout<<a[i]<<endl;
    queue<vector<ll>> q, tq;
    ll ne=0;
    if(aa[st.fst][st.snd].snd==-1){
        coutn()
        return 0;
    }
    ne=aa[st.fst][st.snd].snd;
    q.push({st.fst, st.snd, ne});
    // vector<string> tmp;
    // tmp=aa;
    vector<vector<ll>> d={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    vector<vector<bool>> tsen(h, vector<bool>(w, false));
    seen[st.fst][st.snd]=true;
    while(!q.empty()){
        vector<vector<bool>> tsen(h, vector<bool>(w, false));
        ll y=q.front()[0], x=q.front()[1], z=q.front()[2];
        q.pop();
        // coc3(y, x, z);
        tq.push({y, x, z});
        tsen[y][x]=true;
        while(!tq.empty()){
            ll ty=tq.front()[0], tx=tq.front()[1], tz=tq.front()[2];
            tq.pop();
            // coc3(ty, tx, tz);
            // coc(a[ty][tx])
            if(aa[ty][tx].snd!=-1 and !seen[ty][tx]){
                // wow()
                seen[ty][tx]=true;
                q.push({ty, tx, aa[ty][tx].snd});
            }
            if(tz==0) continue;
            // coc3(ty, tx, tz)
            rep(i, 4){
                ll ny=ty+d[i][0], nx=tx+d[i][1];
                if(ny>=0 and ny<h and nx>=0 and nx<w and a[ny][nx]!='#' and !tsen[ny][nx]){
                    tsen[ny][nx]=true;
                    // coc(a[ny][nx])
                    tq.push({ny, nx, tz-1});
                    if(ny==gl.fst and nx==gl.snd){
                        couty()
                        return 0;
                    }
                }
            }
        }
    }
    coutn()
}