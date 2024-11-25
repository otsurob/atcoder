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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    ll h, w, k;
    cin>>h>>w>>k;
    vector<string> c(h);
    cinv(c, h);
    ll ans=0;
    for(ll i=0; i<(1<<h); i++){
        for(ll j=0; j<(1<<w); j++){
            vector<vector<bool>> check(h, vector<bool>(w, true));
            // wow();
            rep(x, h){
                rep(y, w){
                    ll wari1=1<<x;
                    ll wari2=1<<y;
                    // cout<<x<<y<<endl;
                    if((i/wari1)%2==1) rep(l, w) check[x][l]=false;
                    if((j/wari2)%2==1) rep(l, h) check[l][y]=false;
                }
            }
            ll cnt=0;
            rep(l, h)rep(m, w){
                // cout<<c[l][m]<<endl;
                if(check[l][m] and c[l][m]=='#') cnt++;
            }
            if(cnt==k) ans++;
        }
    }
    cout<<ans<<endl;
}