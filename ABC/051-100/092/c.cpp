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
    int n, sum=0;
    cin>>n;
    vector<int> a(n);
    cin>>a[0];
    sum+=abs(a[0]);
    rep2(1, i, n){
        cin>>a[i];
        sum+=abs((a[i]-a[i-1]));
    }
    sum+=abs(a[n-1]);
    // cout<<sum<<endl;
    cout<<sum-abs(a[0])-abs(a[0]-a[1])+abs(a[1])<<endl;
    rep2(1, i, n-1) cout<<sum-abs(a[i-1]-a[i])-abs(a[i]-a[i+1])+abs(a[i-1]-a[i+1])<<endl;
    cout<<sum-abs(a[n-2]-a[n-1])-abs(a[n-1])+abs(a[n-2])<<endl;
}