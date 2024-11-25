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
    vector<ll> x(q);
    cinv(x, q);
    rep(i, q)x[i]--;
    vector<ll> a(n), b(n);
    rep(i, n){
        a[i]=i;
        b[i]=i;
    }
    rep(i, q){
        ll now=b[x[i]], nx;
        if(now==n-1){
            nx=a[now-1];
            b[x[i]]=b[x[i]]-1;
            b[nx]=b[nx]+1;
            swap(a[now], a[now-1]);
        }else{
            nx=a[now+1];
            b[x[i]]=b[x[i]]+1;
            b[nx]=b[nx]-1;
            swap(a[now], a[now+1]);
        }
        // ll nx= now!=n-1? a[now+1]:a[now-1];
        // b[x[i]] = now!=n-1?b[x[i]]+1:b[x[i]]-1;
        // b[nx] = (b[nx]+n-1)%n;
        // swap(a[now], a[(now+1)%n]);
    }
    rep(i, n)cout<<a[i]+1<<" ";
    cout<<endl;
}