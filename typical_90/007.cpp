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

ll inf=-9999999999;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    cinv(a, n);
    sort(a.begin(), a.end());
    a.push_back(inf);
    ll q;
    cin>>q;
    vector<pll> p;
    rep(i, q){
        ll b;
        cin>>b;
        p.push_back(pll(b, i));
    }
    vector<ll> ans(q);
    sort(p.begin(), p.end());
    ll now=0;
    ll mn=abs(a[0]-p[0].fst);
    ll i=0;
    p.push_back(pll(-1, -1));
    while(i<q){
        // coc2(now, mn);
        if(abs(p[i].fst-a[now+1])<=mn){
            now++;
        }else{
            ans[p[i].snd]=abs(p[i].fst-a[now]);
            i++;
        }
        mn=abs(p[i].fst-a[now]);
    }
    rep(i, q) cout<<ans[i]<<endl;
}