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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    ll d;
    cin>>d;
    ll sq = round(sqrt(d));
    // cout<<sq<<endl;
    ll x=sq, y=0;
    ll mn=9999999999;
    while(x>=y){
        ll z=x*x+y*y-d;
        mn=min(mn, abs(z));
        if(z>0) x--;
        else y++;
    }
    cout<<mn<<endl;
}