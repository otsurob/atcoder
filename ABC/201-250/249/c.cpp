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
    ll n, k;
    cin>>n>>k;
    vector<string> s(n);
    cinv(s, n);
    ll mx=-1;
    rep(i, (1<<n)){
        vector<ll> cnt(26, 0);
        rep(j, n){
            ll wari = 1<<j;
            if((i/wari)%2==1){
                rep(l, s[j].length())cnt[s[j][l]-'a']++;
            }
        }
        ll sum=0;
        rep(j, 26)if(cnt[j]==k)sum++;
        mx = max(mx, sum);
    }
    cout<<mx<<endl;
}