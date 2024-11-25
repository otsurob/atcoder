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

ll ax, ay, bx, by, cx, cy, dx, dy;

bool linea(ll tx, ll ty){
    return (double)(ty-ay)*(cx-ax)-(cy-ay)*(tx-ax)>0;
}

bool lineb(ll tx, ll ty){
    return (double)(ty-by)*(dx-bx)-(dy-by)*(tx-bx)>0;
}


int main(){
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
    if(linea(bx, by)^linea(dx, dy) and lineb(ax, ay)^lineb(cx, cy)) couty()
    else coutn()
}