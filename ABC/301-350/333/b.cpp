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
    char s1, s2, t1, t2;
    cin>>s1>>s2>>t1>>t2;
    string d="ABCDE";
    ll a1, a2, b1, b2;
    rep(i, 5){
        if(d[i]==s1) a1=i;
        if(d[i]==s2) a2=i;
        if(d[i]==t1) b1=i;
        if(d[i]==t2) b2=i;
    }
    ll a=abs(a1-a2);
    ll b=abs(b1-b2);
    if(a>2) a=5-a;
    if(b>2) b=5-b;
    if(a==b) couty()
    else coutn()
}