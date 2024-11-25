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
    ll n, x, y;
    cin>>n>>x>>y;
    vector<ll> a(n);
    cinv(a, n);
    vector<ll> ax, ay;
    rep2(1, i, n){
        if(i%2==0)ax.push_back(a[i]);
        else ay.push_back(a[i]);
    }
    vector<bool> dpx(20010, false), dpy(20010, false), tmp;
    dpx[a[0]+10005]=true;
    dpy[10005]=true;
    rep(i, ax.size()){
        vector<bool> tmp(20010, false);
        rep(j, dpx.size()){
            if(dpx[j]){
                tmp[j+ax[i]]=true;
                tmp[j-ax[i]]=true;
            }
        }
        dpx=tmp;
    }
    rep(i, ay.size()){
        vector<bool> tmp(20010, false);
        rep(j, dpy.size()){
            if(dpy[j]){
                tmp[j+ay[i]]=true;
                tmp[j-ay[i]]=true;
            }
        }
        dpy=tmp;
    }
    if(dpx[x+10005] and dpy[y+10005])couty()
    else coutn()
}