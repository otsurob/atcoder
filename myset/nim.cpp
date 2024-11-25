#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
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

// ↓Nim
// 複数コインが積まれているn個の山がある
// 2人のプレイヤーが順番に1つの山から好きな枚数のコインをとる
// コインが取れなくなった(全山0で順番がまわって来た)方の負け

// 全山の初期のコインの枚数を全てxorしたとき、0なら後手必勝、それ以外なら先手必勝

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    cinv(a, n);
    ll x_sum=0;
    rep(i, n){
        x_sum ^=a[i];
    }
    if(x_sum==0)cout<<"Second"<<endl; //後手必勝
    else cout<<"First"<<endl; //先手必勝
}