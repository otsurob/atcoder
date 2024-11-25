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
    ll n, q;
    cin>>n>>q;
    vector<ll> l(n), r(n);
    rep(i, n){
        cin>>l[i]>>r[i];
    }
    vector<ll> ans;
    set<pll, greater<pll>> sl, sr;
    rep(i, n){
        sl.insert(pll(l[i], i));
        sr.insert(pll(r[i], i));
    }
    while(q--){
        ll t, x;
        cin>>t>>x;
        x--;
        if(t==1){
            ll a, b;
            cin>>a>>b;
            sl.erase(pll(l[x], x));
            sr.erase(pll(r[x], x));
            l[x]=a, r[x]=b;
            sl.insert(pll(a, x));
            sr.insert(pll(b, x));
        }else{
            ll bd=0, num, id;
            for(pll c: sl){
                if(bd==x){
                    num=c.fst;
                    id=c.snd;
                    break;
                }
                bd++;
            }
            ll cnt=0;
            for(pll d: sr){
                // cout<<d<<" ";
                if(d.fst<num)break;
                else if(d.fst==num){
                    if(d.snd>id)continue;
                }
                cnt++;
            }
            // cout<<endl;
            ans.push_back(cnt);
        }
    }
    // for(ll p : sl)cout<<p<<" ";
    // cout<<endl;
    // for(ll p : sr)cout<<p<<" ";
    // cout<<endl;
    rep(i, ans.size()){
        cout<<ans[i]<<endl;
    }
}