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

ll mex(ll x, ll y, ll z){
    rep(j, 4){
        if(j==x or j==y or j==z)continue;
        return j;
    }
    return 3;
}


int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    cinv(a, n);
    string s;
    cin>>s;
    map<pair<char, ll>, ll> mp, tmp;
    ll ans=0;
    rep(i, n)mp[pair<char, ll>(s[i], a[i])]++;
    rep(i, n){
        // cout<<tmp[pair<char, ll>('E', 1)]
        if(s[i]=='E'){
            rep(k, 3)rep(l, 3)ans+=mex(a[i], k, l)*tmp[pair<char, ll>('M', k)]*mp[pair<char, ll>('X', l)];
        }else{
            mp[pair<char, ll>(s[i], a[i])]--;
            tmp[pair<char, ll>(s[i], a[i])]++;
        }
    }
    cout<<ans<<endl;
}