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
    ll n, m, p;
    cin>>n>>m>>p;
    vector<ll> a(n), b(m);
    cinv(a, n);
    cinv(b, m);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<ll> s(m, 0);
    s[0]=b[0];
    rep2(1, i, m) s[i]=s[i-1]+b[i];
    ll l=0, r=m-1;
    ll sum=0;
    // rep(i, n) coc2(a[i], b[i]);
    while(r>=0 and l<n){
        if(a[l]+b[r]<p){
            sum+=s[r]+a[l]*(r+1);
            sum+=p*(m-r-1);
            // coc3(sum, l, r);
            l++;
        }else{
            r--;
        }
    }
    if(l!=n){
        sum+=(n-l)*m*p;
    }
    // if(r!=-1)
    cout<<sum<<endl;
}