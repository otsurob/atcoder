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
    ll n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    ll t=0, a=0;
    ll mxa=0, mxt=0;
    rep(i, n){
        if(s[i]=='0'){
            t=0;
            a=0;
        }
        else if(s[i]=='1') t++;
        else{
            a++;
            t++;
        }
        mxa=max(mxa, a);
        mxt=max(mxt, t);
    }
    cout<<max(mxt-m, mxa)<<endl;
}