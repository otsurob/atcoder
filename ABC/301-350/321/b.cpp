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
#define coc(a) cout<<a<<endl;;
#define coc2(a, b) cout<<a<<" "<<b<<endl;
#define coc3(a, b, c) cout<<a<<" "<<b<<" "<<c<<endl;
#define coc4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
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
    vector<ll> a(n-1);
    cinv(a, n-1);
    sort(a.begin(), a.end());
    ll sum=0;
    rep(i, n-1) sum+=a[i];
    ll sum1=sum-a[0], sum2=sum-a[n-2], sum3=sum2-a[0];
    // coc4(sum, sum1, sum2, sum3)
    if(sum2>=x) cout<<0<<endl;
    else if(sum1==x) cout<<a[n-2]<<endl;
    else{
        ll ans=x-sum3;
        if(ans>=a[0] and ans<=a[n-2]) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}