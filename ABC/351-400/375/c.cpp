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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

pll change(ll y, ll x, ll n){
    return pll(x, n-1-y);
}

int main(){
    ll n;
    cin>>n;
    vector<string> a(n);
    cinv(a, n);
    vector<vector<char>> b(n, vector<char>(n, 'a'));
    pll nz;
    rep(i, n/2){
        ll m=(i+1)%4;
        rep2(i, j, n-i-1){
            nz = pll(0+i, j);
            rep(k, m) nz = change(nz.fst, nz.snd, n);
            b[nz.fst][nz.snd] = a[0+i][j];
            nz = pll(j, n-1-i);
            rep(k, m) nz = change(nz.fst, nz.snd, n);
            b[nz.fst][nz.snd] = a[j][n-1-i];
            nz = pll(n-1-i, n-1-j);
            rep(k, m) nz = change(nz.fst, nz.snd, n);
            b[nz.fst][nz.snd] = a[n-1-i][n-1-j];
            nz = pll(n-1-j, 0+i);
            rep(k, m) nz = change(nz.fst, nz.snd, n);
            b[nz.fst][nz.snd] = a[n-1-j][0+i];
            // coc2(nz.fst, nz.snd)
        }
        // rep(p, n){
        //     rep(q, n)cout<<b[p][q];
        //     codl();
        // }
    }
    rep(i, n){
        rep(j, n)cout<<b[i][j];
        codl();
    }
}