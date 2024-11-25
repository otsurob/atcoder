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
    ll n;
    cin>>n;
    vector<string> s(n);
    cinv(s, n);
    vector<vector<vector<vector<bool>>>> seen(n);
    rep(i, n)seen[i].resize(n);
    rep(i, n)rep(j, n)seen[i][j].resize(n);
    rep(i, n)rep(j, n)rep(k, n)seen[i][j][k].resize(n, false);
    vector<vector<ll>> d={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<pll> st(2);
    ll cnt=0;
    rep(i, n)rep(j, n){
        if(s[i][j]=='P'){
            st[cnt]=pll(i, j);
            cnt++;
        }
    }
    queue<vector<ll>> q;
    q.push({st[0].fst, st[0].snd, st[1].fst, st[1].snd, 0});
    seen[st[0].fst][st[0].snd][st[1].fst][st[1].snd];
    while(!q.empty()){
        vector<ll> p=q.front();
        ll y1=p[0], x1=p[1], y2=p[2], x2=p[3], c=p[4];
        q.pop();
        if(y1==y2 and x1==x2){
            cout<<c<<endl;
            return 0;
        }
        rep(i, 4){
            ll ny1=y1+d[i][0], nx1=x1+d[i][1], ny2=y2+d[i][0], nx2=x2+d[i][1];
            if(ny1>=0 and ny1<n and nx1>=0 and nx1<n and s[ny1][nx1]!='#'){}
            else{
                ny1=y1;
                nx1=x1;
            }
            if(ny2>=0 and ny2<n and nx2>=0 and nx2<n and s[ny2][nx2]!='#'){}
            else{
                ny2=y2;
                nx2=x2;
            }
            if(!seen[ny1][nx1][ny2][nx2]){
                q.push({ny1, nx1, ny2, nx2, c+1});
                seen[ny1][nx1][ny2][nx2]=true;
            }
        }
    }
    cout<<-1<<endl;
}