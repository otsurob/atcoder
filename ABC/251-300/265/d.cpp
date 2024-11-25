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
    ll n, p, q, rr;
    cin>>n>>p>>q>>rr;
    vector<ll> a(n);
    cinv(a, n);
    vector<ll> s(n+1);
    s[0]=0;
    rep(i, n)s[i+1]=s[i]+a[i];
    ll l=0, r=0;
    ll t=p+q+rr;
    ll x, y, z, w;
    // rep(i, n+1)cout<<s[i]<<" ";
    // cout<<endl;
    while(r!=n+1){
        // wow()
        if(s[r]-s[l]>t)l++;
        else if(s[r]-s[l]<t)r++;
        else{
            x=l;
            y=lower_bound(s.begin(), s.end(), p+s[x]) - s.begin();
            // coc2(s[y], s[x])
            if(s[y]!=p+s[x]){
                r++;
                continue;
            }
            z=lower_bound(s.begin(), s.end(), q+s[y]) - s.begin();
            if(s[z]!=q+s[y]){
                r++;
                continue;
            }
            w=lower_bound(s.begin(), s.end(), rr+s[z]) - s.begin();
            if(s[w]!=rr+s[z]){
                r++;
                continue;
            }
            couty()
            return 0;
        }
    }
    coutn()
}