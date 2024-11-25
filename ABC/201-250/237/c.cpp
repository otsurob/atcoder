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
#define inf 9999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    string s;
    cin>>s;
    ll l=0, r=0;
    ll n=s.length();
    rep(i, n){
        if(s[i]=='a')l++;
        else break;
    }
    rrep(i, n){
        if(s[i]=='a')r++;
        else break;
    }
    if(l>r){
        coutn()
        return 0;
    }
    s=s.substr(l, n-l);
    // cout<<s<<endl;
    if(s==""){
        couty()
        return 0;
    }
    rep(i, r)s.pop_back();
    // cout<<s<<endl;
    ll m=s.length();
    string t="";
    // t.reserve();
    // cout<<s<<endl;
    // cout<<t<<endl;
    rrep(i, s.length())t.push_back(s[i]);
    if(s==t)couty()
    else coutn()
}