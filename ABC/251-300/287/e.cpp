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
    ll n;
    cin>>n;
    vector<string> s(n);
    cinv(s, n);
    vector<pair<string, ll>> f;
    rep(i, n)f.push_back(pair<string, ll>(s[i], i));
    sort(f.begin(), f.end());
    vector<ll> ans(n, 0);
    rep(i, n-1){
        ll cnt=0;
        rep(j, min(f[i].fst.length(), f[i+1].fst.length())){
            if(f[i].fst[j]!=f[i+1].fst[j])break;
            cnt++;
        }
        ans[f[i].snd]=max(ans[f[i].snd], cnt);
        ans[f[i+1].snd]=max(ans[f[i+1].snd], cnt);
    }
    rep(i, n)cout<<ans[i]<<endl;
}