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
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> c(4, 0);
    rep(i, n){
        cin>>a[i];
        c[a[i]%4]++;
    }
    c[1]+=c[3];
    if(c[0]>=c[1]) couty()
    else{
        if((c[0]+1==c[1])&&(c[2]==0)) couty()
        else coutn()
    }
}