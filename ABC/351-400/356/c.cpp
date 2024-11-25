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
    ll n, m, k;
    cin>>n>>m>>k;
    vector<ll> c(m);
    vector<char> r(m);
    vector<vector<ll>> a(m);
    rep(i, m){
        cin>>c[i];
        a[i].resize(c[i]);
        rep(j, c[i]){
            cin>>a[i][j];
            a[i][j]--;
        }
        cin>>r[i];
    }
    ll ans=0;
    rep(i, 1<<n){
        bool flag=true;
        vector<bool> f(n, false);
        rep(j, n){
            ll wari = 1<<j;
            if((i/wari)%2==1) f[j]=true;
        }
        // rep(j, n)cout<<f[j]<<" ";
        // cout<<endl;
        rep(j, m){
            ll ch=0;
            rep(x, c[j]){
                if(f[a[j][x]])ch++;
            }
            // cout<<ch<<endl;
            if((ch<k and r[j]=='o'))flag=false;
            if((ch>=k and r[j]=='x'))flag=false;
        }
        // if(flag){
        //     rep(j, n)cout<<f[j]<<" ";
        //     cout<<endl;
        // }
        if(flag)ans++;
    }
    cout<<ans<<endl;
}