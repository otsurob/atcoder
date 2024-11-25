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
    ll l=0, r=1e10;
    ll ans;
    while(l<r){
        ll mid=(l+r)/2;
        ll mns=0, mnn=0, mxs=0, mxn=0;
        rep(i, n){
            if(a[i]>=mid){
                mxs+=a[i]-mid;
                mxn++;
            }
            else{
                mns+=mid-1-a[i];
                mnn++;
            }
        }
        // cout<<mxs<<" "<<mns<<" "<<l<<" "<<r<<endl;
        if(mxs>mns){
            if(mxs-mns<=mnn){
                ans=mxs, mns;
                break;
            }
        }
        else{
            if(mns-mxs<=mxn){
                ans=mns;
                break;
            }
        }
        if(mxs>mns) l=mid;
        else r=mid;
    }
    cout<<ans<<endl;
}