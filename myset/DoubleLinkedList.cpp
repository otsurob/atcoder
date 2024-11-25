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
    ll n;
    cin>>n;
    vector<ll> a(n);
    cinv(a, n);
    ll q;
    cin>>q;
    map<ll, ll> next;
    map<ll, ll> prev;
    next[-1]=a[0];
    prev[0]=a[n-1];
    if(n==1){
        prev[a[0]]=-1;
        next[a[0]]=0;
    }
    else if(n==2){
        prev[a[0]]=-1;
        next[a[0]]=a[1];
        prev[a[1]]=a[0];
        next[a[1]]=0;
    }
    else{
        prev[a[0]]=-1;
        next[a[0]]=a[1];
        prev[a[n-1]]=a[n-2];
        next[a[n-1]]=0;
        rep2(1, i, n-1){
            prev[a[i]]=a[i-1];
            next[a[i]]=a[i+1];
        }
    }
    rep(i, q){
        ll t;
        cin>>t;
        if(t==1){
            ll x, y;
            cin>>x>>y;
            ll tmp=next[x];
            next[x]=y;
            prev[y]=x;
            next[y]=tmp;
            prev[tmp]=y;
        }
        else{
            ll x;
            cin>>x;
            ll tmpp=prev[x];
            ll tmpn=next[x];
            next[tmpp]=tmpn;
            prev[tmpn]=tmpp;
        }
    }
    ll ans=-1;
    ans=next[ans];
    while(ans!=0){
        cout<<ans<<" ";
        ans=next[ans];
    }
    cout<<endl;
}