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

ull gcd(ull x, ull y){
    if(y==0) return x;
    else return gcd(y, x%y);
}


ull lcm(ull x, ull y){
    return x/gcd(x, y)*y;
}

int main(){
    ull a, b;
    cin>>a>>b;
    ull g = gcd(a, b);
    a/=g, b/=g;
    string as=to_string(a), bs=to_string(b), gs=to_string(g);
    ll aa=as[0]-'0', bb=bs[0]-'0', gg=gs[0]-'0';
    ll hd=aa*bb*gg;
    ll keta=as.length()+bs.length()+gs.length()+to_string(hd).length()-3;
    // coc3(a, b, g)
    if(keta==19){
        if(a*b*g==1000000000000000000)cout<<(ull)a*b*g<<endl;
        else cout<<"Large"<<endl;
    }
    else if(keta>19)cout<<"Large"<<endl;
    else{
        if(a*b*g>1000000000000000000)cout<<"Large"<<endl;
        else cout<<(ull)a*b*g<<endl;
    }
}