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
    vector<ll> a(n);
    cinv(a, n);
    ll sum=0;
    rep(i, n)sum+=a[i];
    if(sum%10!=0){
        coutn()
        return 0;
    }
    ll ans=sum/10;
    vector<ll> b;
    b=a;
    rep(i, n)b.push_back(a[i]);
    ll l=0, r=0, now=b[0];
    while(r<2*n){
        if(r<l){
            r++;
            now+=b[r];
        }
        if(now==ans){
            couty()
            return 0;
        }
        if(now>ans){
            now-=b[l];
            l++;
        }
        else{
            r++;
            now+=b[r];
        }
    }
    coutn()
}