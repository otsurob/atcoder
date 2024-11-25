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
    string s;
    cin>>n>>s;
    vector<ll> c(n);
    cinv(c, n);
    ll fs1=0, fs2=0;
    if(s[0]=='0') fs2+=c[0];
    else fs1+=c[0];
    rep2(1, i, n){
        if(i%2==1){
            if(s[i]=='0') fs2+=c[i];
            else fs1+=c[i];
        }else{
            if(s[i]=='1') fs2+=c[i];
            else fs1+=c[i];
        }
    }
    ll mn=min(fs1, fs2);
    ll now1=fs1, now2=fs2;
    rep2(1, i, n-1){
        if(i%2==1){
            if(s[i]=='0'){
                now1+=c[i];
                now2-=c[i];
            }
            else{
                now1-=c[i];
                now2+=c[i];
            }
        }else{
            if(s[i]=='0'){
                now1-=c[i];
                now2+=c[i];
            }
            else{
                now1+=c[i];
                now2-=c[i];
            }
        }
        mn=min(mn, min(now1, now2));
        // coc3(now1, now2, mn);
    }
    cout<<mn<<endl;
}