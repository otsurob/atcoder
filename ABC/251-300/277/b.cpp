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
    vector<string> s(n);
    cinv(s, n);
    set<string> st;
    rep(i, n) st.insert(s[i]);
    if(st.size()!=n){
        coutn()
        return 0;
    }
    string c1="HDCS", c2="A23456789TJQK";
    ll flag=0;
    rep(i, n){
        flag=0;
        rep(j, 4){
            if(s[i][0]==c1[j]){
                flag++;
                break;
            }
        }
        rep(j, 13){
            if(s[i][1]==c2[j]){
                flag++;
                break;
            }
        }
        if(flag!=2){
            coutn()
            return 0;
        }
    }
    couty()
}