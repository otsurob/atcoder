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


pll calc(ll tl, ll tr){
    ll tc=0, tx=1;
    ll sum=0, mod=100;
    while(tx<tr-tl)tx*=2, tc++;
    tx/=2, tc--;
    ll y=(tl/tx)*tx+tx;
    if(tl%tx==0)y-=tx;
    if(y+tx>tr)tx/=2, tc--;
    ll z=(tl/tx)*tx+tx;
    if(tl%tx==0)z-=tx;
    return pll(tc, (z/tx-1));
}


int main(){
    ll n, l, r;
    cin>>n>>l>>r;
    ll c=0, x=1;
    ll sum=0, mod=100;
    while(x<r-l)x*=2, c++;
    x/=2, c--;
    ll y=(l/x)*x+x;
    if(l%x==0)y-=x;
    if(y+x>r)x/=2, c--;
    ll z=(l/x)*x+x;
    if(l%x==0)z-=x;
    queue<pll> q;
    if(l!=(powl(2, c)*((z/x)-1)))q.push(pll(l, (powl(2, c)*((z/x)-1))));
    if(r!=(powl(2, c)*(z/x)))q.push(pll((powl(2, c)*(z/x)), r));
    cout<<'?'<<" "<<c<<" "<<(z/x)-1<<endl;
    while(!q.empty()){
        ll ret;
        cin>>ret;
        sum+=ret;
        sum%=mod;
        ll a=q.front().fst, b=q.front().snd;
        q.pop();
        cout<<'?'<<" "<<a<<" "<<b<<endl;
        if(l!=a)q.push(calc(l, (powl(2, a)*(b))));
        if(b!=r)q.push(calc((powl(2, a)*(b)), r));
    }
    cout<<'!'<<" "<<sum%mod<<endl;
    return 0;
}