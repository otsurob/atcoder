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
    vector<ll> a(n);
    cinv(a, n);
    sort(a.begin(), a.end());
    ll count=0;
    ll r=0, l=0;
    ll sum=0;
    rep(i, n){
        if(a[i]<m){
            count++;
            r++;
        }
        else break;
    }
    r--;
    ll mx=count;
    while(r<n-1){
        if(a[r+1]-a[l]<m){
            count++;
            r++;
        }
        else{
            count--;
            l++;
        }
        mx=max(mx, count);
    }
    cout<<mx<<endl;

}