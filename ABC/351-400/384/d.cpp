#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<' ';
#define codl() cout<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
#define decout(a) cout<<fixed<<setprecision(15)<<a<<endl;
#define wow() cout<<"wow"<<endl;
#define coc(a) cout<<a<<endl;;
#define coc2(a, b) cout<<a<<" "<<b<<endl;
#define coc3(a, b, c) cout<<a<<" "<<b<<" "<<c<<endl;
#define coc4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define pll pair<ll, ll>
#define fst first
#define snd second
#define inf 999999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll n, s;
    cin>>n>>s;
    vector<ll> a(n);
    cinv(a, n);
    ll sum=0;
    rep(i, n)sum+=a[i];
    s%=sum;
    if(s==0){
        couty()
        return 0;
    }
    // coc(s)
    ll m=0;
    ll l=0, r=0;
    while(true){
        // coc(m);
        if(s==m){
            couty()
            return 0;
        }else if(s>m){
            if(r==3*n)break;
            m+=a[r%n];
            r++;
        }else{
            if(l==3*n)break;
            m-=a[l%n];
            l++;
        }
    }
    if(s==m){
        couty();
        return 0;
    }
    // m+=sum;
    // l=0, r=0;
    // while(true){
    //     // coc(m);
    //     if(s==m){
    //         couty()
    //         return 0;
    //     }else if(s>m){
    //         if(r==n)break;
    //         m+=a[r];
    //         r++;
    //     }else{
    //         if(l==n)break;
    //         m-=a[l];
    //         l++;
    //     }
    // }
    // if(s==m){
    //     couty();
    //     return 0;
    // }
    coutn()
}