#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    int n, k, mx=1e8;
    cin>>n>>k;
    int mni;
    vector<ll> a(n);
    rep(i, n){
        cin>>a[i];
        if(a[i]==1) mni=i;
    }
    rep(i, k){
        if((mni-i<0)||(n-mni-1<0)) continue;
        int l = (mni-i)/(k-1);
        if((mni-i)%(k-1)!=0) l++;
        int r = (n-mni-k+i)/(k-1);
        if((n-mni-k+i)%(k-1)!=0) r++;
        // cout<<mni<<i<<mx<<l<<r<<l+r+1<<endl;
        mx = min(mx, l+r+1);
    }
    cout<<mx<<endl;
}