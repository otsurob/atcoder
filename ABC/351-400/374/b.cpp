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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    string s, t;
    cin>>s>>t;
    rep(i, min(s.length(), t.length())){
        if(s[i]!=t[i]){
            cout<<i+1<<endl;
            return 0;
        }
    }
    if(s.length()==t.length()){
        cout<<0<<endl;
        return 0;
    }else{
        cout<<min(s.length(), t.length())+1<<endl;
    }
}