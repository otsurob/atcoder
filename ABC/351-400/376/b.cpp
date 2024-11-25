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
#define inf 9999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll n, q;
    cin>>n>>q;
    vector<char> r(q);
    vector<ll> t(q);
    rep(i, q)cin>>r[i]>>t[i];
    rep(i, q)t[i]--;
    ll nl=0, nr=1;
    ll ans=0;
    ll cnt=0;
    rep(i, q){
        if(r[i]=='L'){
            ll tl=nl;
            cnt=0;
            while(tl!=t[i]){
                tl+=1;
                tl%=n;
                cnt++;
                if(tl==nr){
                    cnt=0;
                    break;
                }
            }
            ans+=cnt;
            tl=nl;
            while(tl!=t[i]){
                tl--;
                if(tl<0)tl+=n;
                // tr%=n;
                cnt++;
                if(tl==nr){
                    cnt=0;
                    break;
                }
            }
            ans+=cnt;
            nl=t[i];
        }else{
            ll tr=nr;
            cnt=0;
            while(tr!=t[i]){
                tr+=1;
                tr%=n;
                cnt++;
                if(tr==nl){
                    cnt=0;
                    break;
                }
            }
            ans+=cnt;
            tr=nr;
            while(tr!=t[i]){
                tr--;
                if(tr<0)tr+=n;
                // tr%=n;
                cnt++;
                if(tr==nl){
                    cnt=0;
                    break;
                }
            }
            ans+=cnt;
            nr=t[i];
        }
        // coc3(ans, nl, nr)
    }
    cout<<ans<<endl;
}