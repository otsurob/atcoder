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
    vector<ll> p(n);
    cinv(p, n);
    if(n==3){
        cout<<3<<endl;
        return 0;
    }
    vector<ll> r(n);
    rep(i, n){
        r[p[i]]=(p[i]+n-i)%n;
    }
    // rep(i, n)cout<<r[i]<<" ";
    // cout<<endl;
    sort(r.begin(), r.end());
    ll mx=-1;
    vector<ll> sum(n, 0);
    rep(i, n){
        if(r[i]==0){
            sum[0]++;
            sum[2]--;
            sum[n-1]++;
        }else if(r[i]==n-1){
            sum[0]++;
            sum[1]--;
            sum[n-2]++;
        }else{
            if(r[i]-1>=0)sum[r[i]-1]++;
            if(r[i]+2<n)sum[r[i]+2]--;
        }
    }
    ll now=0;
    rep(i, n){
        now+=sum[i];
        mx=max(mx, now);
    }
    cout<<mx<<endl;
}