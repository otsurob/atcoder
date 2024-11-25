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
    ll n, a, b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    ll x=0, y=0, z=0, xc=0, yc=0;
    rep(i, 2*n){
        if(s[i]=='(')x++;
        if(s[i]==')'){
            if(x-y==0){
                x++;
                yc++;
            }
            else{
                y++;
            }
        }
    }
    if(x-y!=0)xc+=(x-y)/2;
    if(a<b*2){
        while(xc!=0 and yc!=0){
            z++;
            xc--, yc--;
        }
    }
    cout<<(ll)z*a+(xc+yc)*b<<endl;
}