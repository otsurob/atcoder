#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    ll n, y;
    cin>>n>>y;
    int a=-1, b=-1, c=-1; 
    rep(i, n+1){
        rep(j, n-i+1){
            ll sum = (10000*i)+(5000*j)+(1000*(n-i-j));
            if(sum==y){
                a=i;
                b=j;
                c=n-i-j;
            }
        }
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
}