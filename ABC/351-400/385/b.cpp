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
int main(){
    ll h, w, x, y;
    cin>>h>>w>>x>>y;
    vector<string> s(h);
    cinv(s, h);
    string t;
    cin>>t;
    x--, y--;
    ll cnt=0;
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    if(s[x][y]=='@'){
        cnt++;
        seen[x][y]=true;
    }
    rep(i, t.length()){
        if(t[i]=='U'){
            if(x-1>=0 and s[x-1][y]!='#'){
                x--;
                if(!seen[x][y] and s[x][y]=='@'){
                    cnt++;
                    seen[x][y]=true;
                }
            }
        }
        if(t[i]=='D'){
            if(x+1<h and s[x+1][y]!='#'){
                x++;
                if(!seen[x][y] and s[x][y]=='@'){
                    cnt++;
                    seen[x][y]=true;
                }
            }
        }
        if(t[i]=='L'){
            if(y-1>=0 and s[x][y-1]!='#'){
                y--;
                if(!seen[x][y] and s[x][y]=='@'){
                    cnt++;
                    seen[x][y]=true;
                }
            }
        }
        if(t[i]=='R'){
            if(y+1<w and s[x][y+1]!='#'){
                y++;
                if(!seen[x][y] and s[x][y]=='@'){
                    cnt++;
                    seen[x][y]=true;
                }
            }
        }
    }
    cout<<x+1<<" "<<y+1<<" "<<cnt<<endl;
}