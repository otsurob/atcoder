#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<' ';
#define codl() cout<<endl;
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
#define inf 999999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    char c = s[0];
    ll cnt=1, c0=0, c1=0;
    bool f=false;
    ll d;
    rep2(1, i, n){
        if(s[i-1]!=s[i]){
            if(s[i-1]=='0'){
                c0++;
            }
            if(s[i-1]=='1'){
                c1++;
            }
        }
        if(c1==k-1){
            d=i;
            f=true;
            break;
        }
    }
    ll x0, x1=-1, xc=1;
    rep2(d+1, i, n){
        if(s[i-1]!=s[i]){
            if(s[i-1]=='0'){
                x0=xc;
                xc=1;
            }else{
                x1=xc;
                break;
            }
        }else{
            xc++;
        }
    }
    if(x1==-1){
        x1=xc;
    }
    string t;
    rep(i, x1)t.push_back('1');
    rep(i, x0)t.push_back('0');
    cout<<s.substr(0, d);
    cout<<t;
    cout<<s.substr(d+t.size(), n-d+t.size());
    codl()
}