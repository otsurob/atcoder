#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    ll n, a, b, p, q, r, s;
    cin>>n>>a>>b;
    cin>>p>>q>>r>>s;
    ll y1=a-b;
    ll y2=a+b-2;
    // cout<<y1<<" "<<y2<<endl;
    rep(i, q-p+1){
        rep(j, s-r+1){
            if((i+p-1==j+r-1+y1)||(i+p-1==-(j+r-1)+y2)) cout<<"#";
            else cout<<".";
        }
        cout<<endl;
    }
}