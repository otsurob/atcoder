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

int main(){
    ll n;
    cin>>n;
    ll m=powl(3, n);
    ll k=powl(3, n-1);
    vector<vector<char>> ans(m, vector<char>(m, '#'));
    rep(l, n){
        rep(i, m){
            rep(j, m){
                ll c=pow(3, l+1);
                ll d1=i%c, d2=j%c;
                if(d1>=powl(3, l) and d1<2*powl(3, l) and d2>=powl(3, l) and d2<2*powl(3, l))ans[i][j]='.';
            }
        }
    }
    rep(i, m){
        rep(j, m){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}