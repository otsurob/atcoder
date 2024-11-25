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
    int q, n;
    ll x;
    cin>>q;
    vector<ll> a;
    vector<ll> ans;
    rep(i, q){
        cin>>n;
        if(n==1){
            cin>>x;
            a.push_back(x);
        }else{
            cin>>x;
            ans.push_back(a[a.size()-x]);
        }
    }
    for(ll y : ans) cout<<y<<endl;
}