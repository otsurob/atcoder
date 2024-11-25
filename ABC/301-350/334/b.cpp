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


// ll mfloor(ll x, ll y){
//     ll n=(x%y+y)%y;
//     return (x-n)/y;
// }


// int main(){
//     ll a, m, l, r;
//     cin>>a>>m>>l>>r;
//     l-=a;
//     r-=a;
//     cout<<(ll)(mfloor(r, m)-mfloor(l-1, m))<<endl;
// }

int main(){
    ll a, m, l, r;
    cin>>a>>m>>l>>r;
    l-=a;
    r-=a;
    ll ans;
    ll ln=abs(l)/m, rn=abs(r)/m;
    if((l>=0 and r>=0) or (l<0 and r<0)){
        ans=abs(ln-rn);
        if(min(abs(l), abs(r))%m==0) ans++;
    }else{
        ans=ln+rn+1;
    }
    cout<<ans<<endl;
}