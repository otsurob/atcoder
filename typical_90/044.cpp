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
    ll n, q;
    cin>>n>>q;
    vector<ll> a(n);
    cinv(a, n);
    ll t, x, y;
    ll cnt=0;
    vector<ll> ans={};
    while(q--){
        cin>>t>>x>>y;
        if(t==1){
            x--, y--;
            swap(a[(x+10*n-cnt)%n], a[(y+10*n-cnt)%n]);
        }else if(t==2){
            cnt++;
        }else{
            x--;
            ans.push_back(a[(x+10*n-cnt)%n]);
        }
    }
    // rep(i, n)cout<<a[i]<<" ";
    // cout<<endl;
    // wow()
    rep(i, ans.size())cout<<ans[i]<<endl;
    // wow()
}