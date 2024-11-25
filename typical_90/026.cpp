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
    vector<ll> a(n-1), b(n-1);
    vector<vector<ll>> g(n);
    rep(i, n-1){
        cin>>a[i]>>b[i];
        a[i]--, b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    vector<vector<ll>> ans(2);
    vector<bool> seen(n, false);
    queue<pll> q;
    q.push(pll(0, 0));
    seen[0]=true;
    while(!q.empty()){
        ll x=q.front().fst, y=q.front().snd;
        q.pop();
        for(ll z : g[x]){
            if(!seen[z]){
                seen[z]=true;
                ll m=(y+1)%2;
                q.push(pll(z, m));
                ans[m].push_back(z+1);
            }
        }
    }
    if(ans[0].size()>ans[1].size()){
        sort(ans[0].begin(), ans[0].end());
        rep(i, n/2)cout<<ans[0][i]<<" ";
        cout<<endl;
    }else{
        sort(ans[1].begin(), ans[1].end());
        rep(i, n/2)cout<<ans[1][i]<<" ";
        cout<<endl;
    }

}