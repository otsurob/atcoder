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
    int n, q;
    cin>>n;
    vector<int> a(n);
    rep(i, n) cin>>a[i];
    cin>>q;
    vector<vector<ll>> qv(q, vector<ll>(3));
    rep(i, q){
        cin>>qv[i][0];
        if(qv[i][0]==1) cin>>qv[i][1]>>qv[i][2];
        else cin>>qv[i][1];
    }
    rep(i, q){
        if(qv[i][0]==1) a[qv[i][1]-1]=qv[i][2];
        else cout<<a[qv[i][1]-1]<<endl;
    }
}