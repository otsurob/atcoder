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
    vector<string> s(h);
    cinv(s, h);
    vector<vector<ll>> c(h, vector<ll>(w, 0));
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    vector<vector<ll>> d={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    rep(i, h)rep(j, w){
        if(s[i][j]=='#'){
            c[i][j]=2;
            rep(k, 4){
                if(i+d[k][0]>=0 and i+d[k][0]<h and j+d[k][1]>=0 and j+d[k][1]<w){
                    if(c[i+d[k][0]][j+d[k][1]]==0) c[i+d[k][0]][j+d[k][1]]=1;
                }
            }
        }
    }
    // rep(i, h){
    //     rep(j, w){
    //         cout<<c[i][j];
    //     }
    //     cout<<endl;
    // }
    queue<pll> q;
    ll mx=-1, cnt=0;
    pll sta=pll(-1, -1);
    rep(i, h)rep(j, w){
        cnt=0;
        if(!seen[i][j] and c[i][j]==0){
            sta=pll(i, j);
            q.push(sta);
            cnt++;
            seen[sta.fst][sta.snd]=true;
            set<pll> st;
            while(!q.empty()){
                ll y=q.front().fst, x=q.front().snd;
                q.pop();
                rep(k, 4){
                    ll ny=y+d[k][0], nx=x+d[k][1];
                    if(y+d[k][0]>=0 and y+d[k][0]<h and x+d[k][1]>=0 and x+d[k][1]<w){
                        if(!seen[ny][nx] and c[ny][nx]==0){
                            q.push(pll(ny, nx));
                            seen[ny][nx]=true;
                            cnt++;
                        }
                        if(c[ny][nx]==1){
                            st.insert(pll(ny, nx));
                        }
                    }
                }
            }
            cnt+=st.size();
            mx=max(mx, cnt);
            // coc4(i, j, cnt, mx)
        }
    }
    if(sta==pll(-1, -1)){
        cout<<1<<endl;
        return 0;
    }
    cout<<mx<<endl;
}