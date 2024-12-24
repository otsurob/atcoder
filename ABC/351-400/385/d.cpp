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
    ll n, m, sx, sy;
    cin>>n>>m>>sx>>sy;
    vector<ll> x(n), y(n);
    rep(i, n){
        cin>>x[i]>>y[i];
        // x[i]--, y[i]--;
    }
    vector<char> d(m);
    vector<ll> c(m);
    rep(i, m)cin>>d[i]>>c[i];
    map<ll, set<ll>> xst, yst;
    rep(i, n){
        xst[x[i]].insert(y[i]);
        xst[x[i]].insert(-inf);
        xst[x[i]].insert(inf);
        yst[y[i]].insert(x[i]);
        yst[y[i]].insert(-inf);
        yst[y[i]].insert(inf);
    }
    ll cnt=0;
    rep(i, m){
        if(d[i]=='U'){
            if(!xst[sx].empty() and xst[sx].size()!=2){
                auto za=xst[sx].lower_bound(sy);
                auto zb=xst[sx].lower_bound(sy+c[i]);
                vector<ll> tmp={};
                auto it=za;
                while(it!=xst[sx].end() and *it<*zb+1){
                    cnt++;
                    tmp.push_back(*it);
                    it++;
                }
                for(ll t : tmp){
                    xst[sx].erase(t);
                    yst[t].erase(sx);
                }
            }
            sy+=c[i];
        }
        if(d[i]=='D'){
            if(!xst[sx].empty() and xst[sx].size()!=2){
                auto za=xst[sx].lower_bound(sy);
                auto zb=xst[sx].lower_bound(sy-c[i]);
                // zb--;
                vector<ll> tmp={};
                auto it=za;
                while(*it>*zb-1){
                    cnt++;
                    tmp.push_back(*it);
                    it--;
                }
                for(ll t : tmp){
                    xst[sx].erase(t);
                    yst[t].erase(sx);
                }
            }
            sy-=c[i];
        }
        if(d[i]=='L'){
            if(!yst[sy].empty() and yst[sy].size()!=2){
                auto za=yst[sy].lower_bound(sx);
                auto zb=yst[sy].lower_bound(sx-c[i]);
                // zb--;
                vector<ll> tmp={};
                auto it=za;
                while(*it>*zb-1){
                    cnt++;
                    tmp.push_back(*it);
                    it--;
                }
                for(ll t : tmp){
                    yst[sy].erase(t);
                    xst[t].erase(sy);
                }
            }
            sx-=c[i];
        }
        if(d[i]=='R'){
            if(!yst[sy].empty() and yst[sy].size()!=2){
                auto za=yst[sy].lower_bound(sx);
                auto zb=yst[sy].lower_bound(sx+c[i]);
                vector<ll> tmp={};
                auto it = za;
                while(it!=xst[sx].end() and *it<*zb+1){
                    cnt++;
                    tmp.push_back(*it);
                    it++;
                }
                for(ll t : tmp){
                    yst[sy].erase(t);
                    xst[t].erase(sy);
                }
            }
            sx+=c[i];
        }
    }
    cout<<sx<<" "<<sy<<" "<<cnt<<endl;
}