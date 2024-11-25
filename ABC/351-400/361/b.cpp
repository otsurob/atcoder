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
    ll a, b, c, d, e, f, g, h, i, j, k, l;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;
    ll flag=0;
    if((a<=g and g<d) or (a<j and j<=d) or (g<=a and a<j) or (g<d and d<=j))flag++;
    if((b<=h and h<e) or (b<k and k<=e) or (h<=b and b<k) or (h<e and e<=k))flag++;
    if((c<=i and i<f) or (c<l and l<=f) or (i<=c and c<l) or (i<f and f<=l))flag++;

    if(flag==3)couty()
    else coutn()
}