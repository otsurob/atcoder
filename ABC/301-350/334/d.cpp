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
    sort(a.begin(), a.end());
    vector<ll> s(n);
    s[0]=a[0];
    rep2(1, i, n) s[i]=s[i-1]+a[i];
    ll l=0, r=n-1, mid;
    ll qu;
    vector<ll> ans;
    while(q--){
        cin>>qu;
        l=-1, r=n;
        while(l+1<r){
            mid=(l+r)/2;
            if(s[mid]<=qu) l=mid;
            else r=mid;
        }
        ans.push_back(l+1);
    }
    rep(i, ans.size()) cout<<ans[i]<<endl;
}