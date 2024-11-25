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
    ll n;
    cin>>n;
    ll m=0, t=1;
    while(t<n){
        m++;
        t*=2;
    }
    cout<<m<<endl;
    ll div=1;
    rep(i, m){
        vector<ll> o={};
        rep(j, n){
            if((j/div)%2!=0)o.push_back(j+1);
        }
        div*=2;
        cout<<o.size()<<" ";
        rep(j, o.size())cout<<o[j]<<" ";
        cout<<endl;
    }
    string s;
    cin>>s;
    ll ans=0;
    rep(i, s.length()){
        if(s[i]=='1')ans+=(1<<i);
    }
    cout<<ans+1<<endl;
}