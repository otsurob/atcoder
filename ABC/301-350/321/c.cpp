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
    ll k;
    cin>>k;
    vector<ll> ans;
    for(ll i=2; i<(1<<10); i++){
        ll t=1;
        ll sm=0;
        rep(j, 10){
            if(i&(1<<j)){
                sm+=j*t;
                t*=10;
            } 
        }
        // if(sm==0) cout<<"i="<<i<<endl;
        ans.push_back(sm);
    }
    sort(ans.begin(), ans.end());
    cout<<ans[k-1]<<endl;
}