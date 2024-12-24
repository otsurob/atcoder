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
    ll h, w, xx;
    cin>>h>>w>>xx;
    ll p, q;
    cin>>p>>q;
    p--, q--;
    vector<vector<ll>> s(h, vector<ll>(w));
    rep(i, h)rep(j, w)cin>>s[i][j];
    ll now=s[p][q];
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    vector<vector<ll>> d={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // pq.push(pll(p, q));
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    seen[p][q]=true;
    rep(i, 4){
        ll ny=p+d[i][0], nx=q+d[i][1];
        if(ny>=0 and ny<h and nx>=0 and nx<w and !seen[ny][nx]){
            pq.push({s[ny][nx], ny, nx});
            seen[ny][nx]=true;
        }
    }
    while(!pq.empty()){
        ll y=pq.top()[1], x=pq.top()[2], c=pq.top()[0];
        pq.pop();
        if(now/xx <= c){
            break;
        }
        now+=c;
        rep(i, 4){
            ll ny=y+d[i][0], nx=x+d[i][1];
            if(ny>=0 and ny<h and nx>=0 and nx<w and !seen[ny][nx]){
                pq.push({s[ny][nx], ny, nx});
                seen[ny][nx]=true;
            }
        }
    }
    cout<<now<<endl;
}
