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
#define inf 999999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    set<ll> le, ri;
    ll nl=0;
    le.insert(inf);
    ri.insert(inf);
    rep2(1, i, n){
        if(s[i]==s[i-1]){
            le.insert(nl);
            ri.insert(i-1);
            nl=i;
        }
    }
    le.insert(nl);
    ri.insert(n-1);
    ri.insert(-1);
    // for(auto x : le){
    //     cout<<x<<" ";
    // }
    // codl()
    // for(auto x : ri){
    //     cout<<x<<" ";
    // }
    codl()
    while(q--){
        ll que, l, r;
        cin>>que>>l>>r;
        l--, r--;
        auto itl=le.upper_bound(l);
        auto itr=ri.lower_bound(r);
        itl--;
        if(que==1){
            if(l!=0){
                if(*itl==l){
                    le.erase(l);
                    ri.erase(l-1);
                }else{
                    le.insert(l);
                    ri.insert(l-1);
                }
            }
            if(*itr==r){
                le.erase(r+1);
                ri.erase(r);
            }else{
                le.insert(r+1);
                ri.insert(r);
            }
        }else{
            itr--;
            if(*itl==*itr+1){
                couty()
            }else{
                coutn()
            }
        }
    }
}