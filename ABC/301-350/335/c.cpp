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
    ll n, q;
    cin>>n>>q;
    deque<pll> d;
    rep(i, n) d.push_back(pll(i+1, 0));
    ll x, y;
    // wow();
    rep(i, q){
        int k;
        cin>>k;
        if(k==1){
            char c;
            cin>>c;
            ll x2=d[0].fst;
            ll y2=d[0].snd;
            if(c=='R') d.push_front(pll(x2+1, y2));
            if(c=='L') d.push_front(pll(x2-1, y2));
            if(c=='U') d.push_front(pll(x2, y2+1));
            if(c=='D') d.push_front(pll(x2, y2-1));
            d.pop_back();
        }
        else{
            ll x;
            cin>>x;
            x--;
            cout<<d[x].fst<<" "<<d[x].snd<<endl;
        }
    }
    // rep(i, d.size()) cout<<d[i].fst<<" "<<d[i].snd<<endl;
}


