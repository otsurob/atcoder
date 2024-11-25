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


bool check(ll h, ll m){
    ll a=h/10, b=h%10, c=m/10, d=m%10;
    ll x=a*10+c, y=b*10+d;
    if(x<=23 and y<=59)return true;
    else return false;
}


int main(){
    ll h, m;
    cin>>h>>m;
    while(true){
        if(check(h, m)){
            cout<<h<<" "<<m<<endl;
            return 0;
        }else{
            m++;
            if(m==60){
                m=0;
                h++;
                if(h==24)h=0;
            }
        }
    }
}