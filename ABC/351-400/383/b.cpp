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
    ll h, w, d;
    cin>>h>>w>>d;
    vector<string> s(h);
    cinv(s, h);
    ll mx=-1;
    ll ch=0;
    rep(i, h)rep(j, w)rep(k, h)rep(l, w){
        // ch++;
        // coc4(i, j, k, l);
        // cout<<s[i][j]<<s[k]
        if(i==k and j==l)continue;
        if(s[i][j]!='.' or s[k][l]!='.')continue;
        ll cnt=0;
        vector<vector<bool>> seen(h, vector<bool>(w, false));
        // wow()
        rep(y, h)rep(x, w){
            if(s[y][x]=='.'){
                // coc("wow");
                if((abs(y-i)+abs(x-j))<=d or (abs(y-k)+abs(x-l))<=d)seen[y][x]=true;
            }
        }
        rep(y, h)rep(x, w)if(seen[y][x])cnt++;
        mx=max(mx, cnt);
    }
    // coc(ch)
    cout<<mx<<endl;
}