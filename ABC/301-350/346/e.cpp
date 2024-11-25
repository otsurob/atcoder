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
    ll h, w, m;
    cin>>h>>w>>m;
    vector<ll> t(m), a(m), x(m);
    rep(i, m){
        cin>>t[i]>>a[i]>>x[i];
        a[i]--;
    }
    vector<ll> c(2000009, 0);
    ll wn=0, hn=0;
    vector<bool> ho(h, false), v(w, false);
    ll sum=0;
    rrep(i, m){
        if(t[i]==1){
            if(!ho[a[i]]){
                ho[a[i]]=true;
                wn++;
                c[x[i]]+=w-hn;
            }
        }else{
            if(!v[a[i]]){
                v[a[i]]=true;
                hn++;
                c[x[i]]+=h-wn;
            }
        }
    }
    ll cnt=0;
    rep(i, c.size()){
        if(c[i]!=0){
            cnt++;
            sum+=c[i];
        }
    }
    if(c[0]==0 and sum!=h*w) cnt++;
    c[0]+=h*w-sum;
    cout<<cnt<<endl;
    rep(i, c.size()) if(c[i]!=0)cout<<i<<" "<<c[i]<<endl;
}