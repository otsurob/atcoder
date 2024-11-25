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
    ll xa, ya, xb, yb, xc, yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    ll ab=((abs(xa-xb)*abs(xa-xb))+(abs(ya-yb)*abs(ya-yb)));
    ll bc=((abs(xc-xb)*abs(xc-xb))+(abs(yc-yb)*abs(yc-yb)));
    ll ca=((abs(xa-xc)*abs(xa-xc))+(abs(ya-yc)*abs(ya-yc)));
    bool flag=false;
    if(ab+bc==ca or bc+ca==ab or ab+ca==bc)flag=true;
    if(flag)couty()
    else coutn()
}