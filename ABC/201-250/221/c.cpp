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
    string s;
    cin>>s;
    ll n=s.length();
    ll mx=-1;
    vector<char> a1, a2;
    string b1, b2;
    rep(i, 1<<n){
        a1={}, a2={};
        b1="", b2="";
        rep(j, n){
            ll wari = 1<<j;
            if((i/wari)%2==1)a1.push_back(s[j]);
            else a2.push_back(s[j]);
        }
        sort(a1.rbegin(), a1.rend());
        sort(a2.rbegin(), a2.rend());
        rep(j, a1.size())b1+=a1[j];
        rep(j, a2.size())b2+=a2[j];
        // coc2(b1, b2);
        if(b1=="" or b2=="")continue;
        ll c1=stoll(b1);
        ll c2=stoll(b2);
        if(c1==0 or c2==0)continue;
        chmax(mx, c1*c2);
    }
    cout<<mx<<endl;
}