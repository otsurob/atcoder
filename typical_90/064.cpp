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
    ll n, q;
    cin>>n>>q;
    vector<ll> a(n);
    cinv(a, n);
    vector<ll> d(n-1);
    rep(i, n-1)d[i]=a[i+1]-a[i];
    vector<ll> ans;
    ll sum=0;
    rep(i, n-1)sum+=abs(d[i]);
    while(q--){
        ll l, r, v;
        cin>>l>>r>>v;
        l--, r--;
        // if(v>0){
        if(l!=0){
            sum-=abs(d[l-1]);
            d[l-1]+=v;
            sum+=abs(d[l-1]);
        }
        if(r!=n-1){
            sum-=abs(d[r]);
            d[r]-=v;
            sum+=abs(d[r]);
        }
        // }
        ans.push_back(sum);
    }
    rep(i, ans.size())cout<<ans[i]<<endl;
}