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
    vector<ll> a(q);
    cinv(a, q);
    rep(i, q)a[i]--;
    vector<ll> ans(n, 0);
    vector<bool> iseven(q, false), isnum(n, false);
    vector<ll> im(q+1, 0);
    ll now=0;
    rep(i, q){
        if(!isnum[a[i]]){
            isnum[a[i]]=true;
            now++;
        }else{
            isnum[a[i]]=false;
            now--;
            iseven[i]=true;
        }
        im[0]+=now;
        im[i+1]-=now;
    }
    // coutv(im, q);
    rep2(1, i, q){
        im[i]+=im[i-1];
    }
    // coutv(im, q);
    // coutv(iseven, q);
    rep(i, q){
        if(iseven[i]){
            // cout<<'#'<<im[i]<<endl;
            ans[a[i]]-=im[i];
        }else{
            // cout<<im[i]<<endl;
            // coc2(a[i], im[i]);
            ans[a[i]]+=im[i];
        }
    }
    rep(i, n){
        cout<<ans[i]<<" ";
    }
    codl()
}