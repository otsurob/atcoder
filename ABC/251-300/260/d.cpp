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
    ll n, k;
    cin>>n>>k;
    vector<ll> p(n);
    cinv(p, n);
    ll inf=9999999999999;
    vector<ll> t;
    vector<ll> ans(n+1, -1);
    map<ll, pll> mp;
    t.push_back(p[0]);
    t.push_back(inf);
    mp[p[0]]=pll(-1, 1);
    if(k==1){
        rep(i, n)ans[p[i]]=i+1;
        rep2(1, i, n+1)cout<<ans[i]<<endl;
        return 0;
    }
    rep2(1, i, n){
        auto it = lower_bound(t.begin(), t.end(), p[i]);
        ll dis=it-t.begin();
        // coc(dis)
        if(*it==inf){
            // wow()
            t[dis]=p[i];
            t.push_back(inf);
            mp[p[i]]=pll(-1, 1);
        }
        else{
            mp[p[i]]=pll(t[dis], mp[t[dis]].snd+1);
            t[dis]=p[i];
            if(mp[p[i]].snd==k){
                ll x=p[i];
                ans[x]=i+1;
                // coc(x)
                while(true){
                    x=mp[x].fst;
                    ans[x]=i+1;
                    // coc(x)
                    if(mp[x].fst==-1)break;
                }
                t.erase(t.begin()+dis);
            }
        }
    }
    rep2(1, i, n+1)cout<<ans[i]<<endl;
}