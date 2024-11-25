#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll n;
    cin>>n;
    vector<ll> h(n);
    cinv(h, n);
    ll ans=0, now=0;
    rep(i, n){
        if(ans%3==1){
            if(h[i]>=4){
                h[i]-=4;
                ans+=2;
            }
            else{
                if(h[i]==1){
                    ans++;
                }else{
                    ans+=2;
                }
                continue;
            }
        }
        else if(ans%3==2){
            h[i]-=3;
            ans++;
            if(h[i]<0)continue;
        }
        ll m=h[i]/5;
        ans+=m*3;
        h[i]%=5;
        if(h[i]==0)continue;
        if(h[i]==1)ans++;
        else if(h[i]==2)ans+=2;
        else ans+=3;
    }
    cout<<ans<<endl;
}