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
    ll n;
    cin>>n;
    ll m=1;
    vector<ll> a1, a2, a3;
    vector<ll> ans;
    rep(i, 15){
        a1.push_back(m);
        a2.push_back(m);
        a3.push_back(m);
        m*=10;
        m++;
    }
    rep(i, 15)rep(j, i+1)rep(k, j+1){
        ans.push_back(a1[i]+a2[j]+a3[k]);
    }
    sort(ans.begin(), ans.end());
    cout<<ans[n-1]<<endl;
}