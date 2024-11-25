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
    vector<vector<ll>> d(n, vector<ll>(n, 0));
    rep(i, n-1)rep2(i+1, j, n){
        cin>>d[i][j];
    }
    vector<ll> dp((1<<n), 0);
    rep(i, (1<<n)-1){
        ll sta=-1;
        rep(j, n){
            if(!(i&(1<<j))){
                sta=j;
                break;
            }
        }
        rep(j, n){
            ll nx=-1;
            if(!(i&(1<<j))){
                nx=i|(1<<sta)|(1<<j);
                // coc(d[sta][j])
                dp[nx]=max(dp[nx], dp[i]+d[sta][j]);
            }
        }
    }
    // rep(i, (1<<n)-1)cout<<dp[i]<<" ";
    cout<<dp[(1<<n)-1]<<endl;
}