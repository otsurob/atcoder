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
    rep(i, n)a[i]--;
    // wow()
    ll inf=999999999999999;
    vector<ll> seen(n, inf);
    vector<ll> sc(n, -1);
    rep(i, n){
        if(seen[i]!=inf)continue;
        seen[i]=i;
        ll now=a[i];
        ll flag=0;
        while(true){
            // cout<<now<<endl;
            if(seen[now]==inf){
                seen[now]=i;
                now=a[now];
            }
            else{
                if(seen[now]!=i){
                    flag=1;
                    break;
                }
                else{
                    flag=3;
                    break;
                }
            }
        }
        
        if(flag==3){
            if(now==a[now]){
                sc[now]=1;
            }
            else{
                ll cnt=1;
                ll nx=a[now];
                while(nx!=now){
                    cnt++;
                    nx=a[nx];
                }
                // cout<<cnt<<" "<<i<<endl;
                nx=a[now];
                sc[now]=cnt;
                while(nx!=now){
                    sc[nx]=cnt;
                    nx=a[nx];   
                }
            }
        }
    }
    // rep(i, n)cout<<sc[i]<<" ";
    // cout<<endl;
    vector<pll> vis(n, pll(inf, inf));
    vector<ll> ans(n);
    rep(i, n){
        if(sc[i]!=-1){
            ans[i]=sc[i];
            continue;
        }
        if(vis[i]!=pll(inf, inf)){
            ans[i]=ans[vis[i].fst]-vis[i].snd;
        }
        ll di=1;
        ll nx=a[i];
        vis[i]=pll(i, 0);
        while(true){
            if(sc[nx]!=-1){
                ans[i]=sc[nx]+di;
                break;
            }
            // cout<<nx<<endl;
            vis[nx]=pll(i, di);
            di++;
            nx=a[nx];
        }
    }
    ll fa=0;
    rep(i, n)fa+=ans[i];
    cout<<fa<<endl;
}