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
    ll h, w;
    cin>>h>>w;
    vector<vector<ll>> p(h, vector<ll>(w));
    rep(i, h)rep(j, w)cin>>p[i][j];
    ll hw=h*w;
    ll ans=0;
    rep(i, 1<<h){
        vector<ll> cnt(hw+1, 0);
        // ll cnt=0;
        ll f=0;
        rep(j, w){
            ll now=-1, n=0, flag=0;
            rep(k, h){
                ll wari = 1<<k;
                if((i/wari)%2==1){
                    if(now==-1){
                        now=p[k][j];
                        n++;
                    }
                    else{
                        if(p[k][j]!=now){
                            flag=1;
                            break;
                        }
                        n++;
                    }
                }
            }
            if(flag==1 or now==-1)continue;
            cnt[now]+=n;
            // coc2(now, cnt[now])
        }
        // coc2(i, f);
        // if(f==1)continue;
        rep(k, hw+1)chmax(ans, cnt[k]);
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
}