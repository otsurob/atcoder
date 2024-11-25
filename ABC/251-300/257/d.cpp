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
    vector<ll> x(n), y(n), p(n);
    rep(i, n)cin>>x[i]>>y[i]>>p[i];
    vector<vector<ll>> co(n, vector<ll>(n, 0));
    rep(i, n-1){
        rep2(i+1, j, n){
            co[i][j]=(abs(x[i]-x[j])+abs(y[i]-y[j])+p[i]-1)/p[i];
            co[j][i]=(abs(x[i]-x[j])+abs(y[i]-y[j])+p[j]-1)/p[j];
        }
    }
    ll l=0, r=inf;
    while(l+1!=r){
        ll m=(l+r)/2;
        ll mx=0;
        rep(i, n){
            ll cnt=1;
            vector<bool> seen(n, false);
            queue<ll> q;
            q.push(i);
            seen[i]=true;
            while(!q.empty()){
                ll z=q.front();
                q.pop();
                rep(j, n){
                    if(z==j)continue;
                    if(!seen[j] and m>=co[z][j]){
                        q.push(j);
                        seen[j]=true;
                        cnt++;
                    }
                }
            }
            chmax(mx, cnt);
        }
        if(mx==n)r=m;
        else l=m;
    }
    cout<<r<<endl;
}