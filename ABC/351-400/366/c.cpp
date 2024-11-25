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
void chmin(int &a, int b) { a = min(a, b); }
void chmax(int &a, int b) { a = max(a, b); }
int main(){
    ll q;
    cin>>q;
    map<ll, ll> cnt;
    ll ans=0;
    vector<ll> l;
    while(q--){
        ll t;
        cin>>t;
        if(t==1){
            ll x;
            cin>>x;
            if(cnt[x]==0)ans++;
            cnt[x]++;
        }else if(t==2){
            ll x;
            cin>>x;
            cnt[x]--;
            if(cnt[x]==0)ans--;
        }else{
            l.push_back(ans);
        }
    }
    rep(i, l.size())cout<<l[i]<<endl;
}
