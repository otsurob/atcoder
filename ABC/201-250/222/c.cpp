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
bool janken(char a, char b){
    if((a=='G' and b=='C') or (a=='C' and b=='P') or (a=='P' and b=='G'))return true;
    else return false;
}
int main(){
    ll n, m;
    cin>>n>>m;
    vector<string> a(2*n);
    cinv(a, 2*n);
    vector<pll> x;
    rep(i, 2*n)x.push_back(pll(0, i));
    rep(i, m){
        for(ll j=0; j<2*n-1; j+=2){
            if(janken(a[x[j].snd][i], a[x[j+1].snd][i]))x[j].fst--;
            if(janken(a[x[j+1].snd][i], a[x[j].snd][i]))x[j+1].fst--;
        }
        sort(x.begin(), x.end());
    }
    rep(i, 2*n)cout<<x[i].snd+1<<endl;
}