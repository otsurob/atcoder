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
    ll n, x;
    cin>>n>>x;
    ll k;
    cin>>k;
    vector<ll> a(n);
    cinv(a, n);
    vector<ll> b(n+1);
    b[0]=a[0];
    b[n]=x-a[n-1];
    rep2(1, i, n){
        b[i]=a[i]-a[i-1];
    }
    // rep(i, n+1) cout<<b[i];
    // cout<<endl;
    ll l=0, r=x+1;
    while(r-l>1){
        ll mid=(l+r)/2;
        ll cnt=0;
        ll lg=0;
        rep(i, n){
            lg+=b[i];
            if(lg>=mid){
                lg=0;
                cnt++;
            }
        }
        // cout<<l<<" "<<mid<<" "<<r<<endl;
        if(lg+b[n]>=mid) cnt++;
        if(cnt<k+1) r=mid;
        else l=mid;
    }
    cout<<l<<endl;
}