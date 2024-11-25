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

bool isprime(ll x){
    if(x<2) return false;
    else if(x==2) return true;
    else if(x%2==0) return false;

    double lim = sqrt(x);
    for(ll i=3; i<=lim; i+=2){
        if(x%i==0) return false;
    }
    return true;
}


int main(){
    ll t;
    cin>>t;
    vector<ll> v(t);
    rep(i, t) cin>>v[i];
    // cout<<isprime(17)<<endl;
    rep(i, t){
        ll n=1;
        while(n*n*n<=v[i]){
            n++;
            if(v[i]%n==0) break;
        }
        if(v[i]%(n*n)==0) cout<<n<<" "<<v[i]/(n*n)<<endl;
        else{
            ll ans = sqrt(v[i]/n);
            cout<<ans<<" "<<n<<endl;
        }
    }
}