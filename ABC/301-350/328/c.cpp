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
    ll n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<ll> l(q), r(q);
    rep(i, q) cin>>l[i]>>r[i];
    vector<ll> sm(n, 0);
    rep(i, n-1){
        sm[i+1]+=sm[i];
        if(s[i+1]==s[i]) sm[i+1]++;
    }
    rep(i, q) cout<<sm[r[i]-1]-sm[l[i]-1]<<endl;
}