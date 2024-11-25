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
    ll zcnt=0;
    vector<ll> a(n);
    rep(i, n){
        cin>>a[i];
        if(a[i]==0) zcnt++;
    }
    vector<ll> cnt(300000, 0);
    rep(i, n){
        ll m=a[i];
        ll mx=1;
        for(ll j=1; j*j<=a[i]; j++){
            if(m%(j*j)==0) mx=j;
        }
        cnt[m/(mx*mx)]++;
    }
    ll ans=0;
    // if(zcnt>=2) ans+=zcnt*(zcnt-1)/2;
    ans+=zcnt*(n-zcnt);
    // cout<<ans<<endl;
    rep(i, cnt.size()){
        // if(cnt[i]<2) continue;
        ans+=cnt[i]*(cnt[i]-1)/2;
        // cout<<i<<" "<<cnt[i]<<endl;
    }
    cout<<ans<<endl;
}