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


bool isprime(ll x){
    if(x<2) return false;
    else if(x==2) return true;
    else if(x%2==0) return false;

    double lim = sqrt(x);
    for(ll i=3; i<=lim; i+=2){
        if(x%i==0) return false;
    }
    return true;
}


int main(){
    ll n;
    cin>>n;
    vector<ll> p;
    rep2(2, i, 300000)if(isprime(i))p.push_back(i);
    // cout<<p.size()<<endl;
    ll np=p.size();
    ll ans=0;
    ll c=np-1;
    ll sta=-1, flag=0;
    rep(a, np){
        if(flag==1){
            c=sta;
            flag=0;
        }
        rep2(a+1, b, np){
            if(b>=c)break;
            while(b<c){
                // coc(c)
                // coc3(p[a], p[b], p[c]);
                if(p[a]*p[a]*p[b]*p[c]*p[c]>n)c--;
                else{
                    if(flag==0){
                        sta=c;
                        flag=1;
                    }
                    // coc3(p[a], p[b], p[c])
                    ans+=c-b;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}