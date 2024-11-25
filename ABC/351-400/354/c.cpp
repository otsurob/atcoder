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
    vector<ll> a(n), c(n), b;
    rep(i, n)cin>>a[i]>>c[i];
    vector<vector<ll>> info1, info2;
    rep(i, n)info1.push_back({a[i], c[i], i+1});
    rep(i, n)info2.push_back({c[i], a[i], i+1});
    sort(info1.begin(), info1.end());
    sort(info2.begin(), info2.end());
    sort(c.begin(), c.end());

    vector<ll> ans;
    rep(i, n){
        if(c.empty())break;
        ll x=info1[n-1-i][1];
        // cout<<x<<endl;
        // info1.pop_back();
        if(x>c.back())continue;
        ll it=lower_bound(c.begin(), c.end(), x)-c.begin();
        // cout<<it<<endl;
        // coc2(x, it)
        // reverse(c.begin(), c.end());
        rrep2(it, j, c.size()-1){
            // coc(c.back())
            c.pop_back();
            info2.pop_back();
        }
        if(c.back()==x){
            // coc2(c.back(), -1)
            ans.push_back(info2.back()[2]);
            info2.pop_back();
            c.pop_back();
        }
        // reverse(a.begin(), a.end());
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    rep(i, ans.size())cout<<ans[i]<<" ";
    cout<<endl;
}