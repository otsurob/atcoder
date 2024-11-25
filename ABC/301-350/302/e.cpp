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
    vector<set<ll>> g(n);
    vector<ll> cnt(n, 0), ans;
    ll sum=n;
    while(q--){
        ll f;
        cin>>f;
        if(f==1){
            ll a, b;
            cin>>a>>b;
            a--, b--;
            if(g[a].size()==0)sum--;
            if(g[b].size()==0)sum--;
            g[a].insert(b);
            g[b].insert(a);
            // if(cnt[a]==0)sum--;
            // cnt[a]++;
            // if(cnt[b]==0)sum--;
            // cnt[b]++;
        }else{
            ll c;
            cin>>c;
            c--;
            if(g[c].size()!=0)sum++;
            for(auto x : g[c]){
                g[x].erase(c);
                if(g[x].size()==0)sum++;
            }
            g[c]={};
        }
        ans.push_back(sum);
    }
    rep(i, ans.size())cout<<ans[i]<<endl;
}