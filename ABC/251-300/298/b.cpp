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
    ll n;
    cin>>n;
    vector<vector<ll>> a(n, vector<ll>(n)), b(n, vector<ll>(n));
    rep(j, n)cinv(a[j], n);
    rep(j, n)cinv(b[j], n);
    vector<vector<ll>> tmp(n, vector<ll>(n));
    ll cnt=0;
    ll sum=0;
    rep(i, n)rep(j, n)if(a[i][j]==1) sum++;
    rep(k, 4){
        cnt=0;
        tmp=a;
        rep(i, n)rep(j, n){
            a[i][j]=tmp[n-1-j][i];
        }
        rep(i, n)rep(j, n){
            if(a[i][j]==1 and b[i][j]==1) cnt++;
        }
        if(cnt==sum){
            couty()
            return 0;
        }
    }
    coutn()
}