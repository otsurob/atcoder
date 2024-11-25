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
    ll n, a, b, c;
    cin>>n>>a>>b>>c;
    ll cn=n/c, bn=(n-(c*cn))/b;
    ll ans=9999999999, now=0;
    // coc2(cn, bn);
    rrep(i, cn+1){
        bn=min((n-(c*i))/b, 9999-i);
        rrep(j, bn+1){
            now=0;
            if((n-(c*i)-(b*j))%a==0){
                now+=(n-(c*i)-(b*j))/a;
                now+=i+j;
                ans=min(ans, now);
            }
        }
    }
    cout<<ans<<endl;
}