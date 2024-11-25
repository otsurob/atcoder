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
    // pll p=pll(1, 2);
    // p.fst=3;
    // coc2(p.fst, p.snd);
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> g(n);
    vector<ll> v(n, 0);
    ll a, c;
    char b, d;
    rep(i, m){
        cin>>a>>b>>c>>d;
        a--, c--;
        g[a].push_back(c);
        g[c].push_back(a);
        v[a]++, v[c]++;
    }
    vector<bool> seen(n, false);
    ll ans1=0, ans2=0;
    rep(i, n){
        if(seen[i]) continue;
        queue<ll> q;
        q.push(i);
        seen[i]=true;
        bool flag=false;
        while(!q.empty()){
            ll x=q.front();
            q.pop();
            if(v[x]!=2) flag=true;
            for(auto y : g[x]){
                if(!seen[y]){
                    q.push(y);
                    seen[y]=true;
                }
            }
        }
        if(flag) ans2++;
        else ans1++;
    }
    coc2(ans1, ans2)
}