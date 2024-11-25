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
    string s, t;
    cin>>s>>t;
    string z;
    z=s.substr(s.length()-t.length(), t.length());
    ll cnt=0;
    vector<bool> c(t.length(), false);
    rep(i, z.length()){
        if(z[i]!='?' and t[i]!='?' and z[i]!=t[i]){
            c[i]=true;
            cnt++;
        }
    }
    if(cnt==0)couty()
    else coutn()
    rep(i, t.length()){
        if(c[i]){
            if(s[i]=='?' or s[i]==t[i]){
                c[i]=false;
                cnt--;
            }
        }else{
            if(s[i]!='?' and t[i]!='?' and s[i]!=t[i]){
                c[i]=true;
                cnt++;
            }
        }
        if(cnt==0)couty()
        else coutn()
    }
}