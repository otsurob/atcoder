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
    vector<ll> c(n), v(n);
    rep(i, n) cin>>c[i]>>v[i];
    ll mx=-1, mxn;
    vector<ll> tl;
    vector<pll> ans;
    ll cn=0, cnt=0;
    rep2(1, i, n){
        if(c[i]==c[i-1]){
            mx=max(mx, v[i]);
            cn++;
        }
        else{
            if(cn!=0){
                ans.push_back(pll(c[i-1], mx));
                cnt+=cn;
            }
            cn=0;
            mx=v[i];
        }
    }
    if(cn!=0){
        ans.push_back(pll(c[n-1], mx));
        cnt+=cn;
    }

    ll d=n-cnt;
    if(d<k){
        cout<<-1<<endl;
        return 0;
    }
    d=d-k;
    
}