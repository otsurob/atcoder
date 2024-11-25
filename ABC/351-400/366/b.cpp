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
void chmin(int &a, int b) { a = min(a, b); }
void chmax(int &a, int b) { a = max(a, b); }
int main(){
    ll n;
    cin>>n;
    vector<string> s(n);
    cinv(s, n);
    ll m=0;
    rep(i, n)m=max(m, (ll)s[i].length());
    // wow()
    // cout<<m<<endl;
    // vector<string> t(m);
    // rep(i, m)
    vector<vector<char>> t(m, vector<char>(n, '*'));
    // wow()
    rep(i, n){
        rep(j, s[i].length()){
            t[j][n-1-i]=s[i][j];
        }
    }
    rep(i, m){
        ll d=n-1;
        while(t[i][d]=='*'){
            t[i][d]=' ';
            d--;
        }
    }
    rep(i, m){
        rep(j, n){
            // if(i==m-1 and t[i][j]=='*')break;
            cout<<t[i][j];
        }
        cout<<endl;
    }
}