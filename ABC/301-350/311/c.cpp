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
#define pll pair<ll, ll>
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    cinv(a, n);
    rep(i,  n) a[i]--;
    vector<bool> seen(n, false);
    ll x=a[0];
    seen[0]=true;
    ll ans;
    while(n--){
        if(seen[x]){
            ans=x;
            break;
        }
        seen[x]=true;
        x=a[x];
    }
    ll y=a[ans];
    vector<ll> v;
    while(y!=ans){
        // cout<<y+1<<" ";
        v.push_back(y+1);
        y=a[y];
    }
    cout<<v.size()+1<<endl;
    rep(i, v.size()) cout<<v[i]<<" ";
    cout<<y+1<<endl;
}