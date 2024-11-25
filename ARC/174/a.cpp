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
    ll n, c;
    cin>>n>>c;
    vector<ll> a(n);
    cinv(a, n);
    ll che=0;
    if(c<1){
        che++;
        // c*=-1;
        // c+=2;
        rep(i, n) a[i]*=-1;
    }
    vector<ll> sum(n, 0);
    sum[0]=a[0];
    rep2(1, i, n){
        sum[i]=sum[i-1]+a[i];
    }
    ll mn=0, mx=0;
    rep(i, n){
        mn=min(mn, sum[i]);
        mx=max(mx, sum[i]-mn);
    }
    if(che==1) cout<<(ll)sum[n-1]*(-1)+((-1)*mx*(c-1))<<endl;
    else cout<<(ll)sum[n-1]+(mx*(c-1))<<endl;

}