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
    ll h, w;
    cin>>h>>w;
    vector<string> s(h);
    rep(i, h) cin>>s[i];
    vector<ll> ch(h), cw(w);
    ll cnt=0, mh=0, mw=0;
    rep(i, h){
        cnt=0;
        rep(j, w){
            if(s[i][j]=='#') cnt++;
        }
        mh=max(mh, cnt);
        ch[i]+=cnt;
    }
    rep(i, w){
        cnt=0;
        rep(j, h){
            if(s[j][i]=='#') cnt++;
        }
        mw=max(mw, cnt);
        cw[i]+=cnt;
    }
    ll ansh, answ;
    rep(i, h)if(ch[i]!=0 and ch[i]<mh) ansh=i+1;
    rep(i, w)if(cw[i]!=0 and cw[i]<mw) answ=i+1;
    cout<<ansh<<" "<<answ<<endl;
}