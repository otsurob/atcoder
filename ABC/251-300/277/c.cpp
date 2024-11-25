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
    ll a, b;
    map<ll, vector<ll>> mp;
    map<ll, bool>seen;
    rep(i, n){
        cin>>a>>b;
        a--, b--;
        seen[a]=false;
        seen[b]=false;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    ll mx=-1;
    queue<ll> q;
    q.push(0);
    seen[0]=true;
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        mx=max(mx, x);
        for(auto y : mp[x]){
            // cout<<y<<" ";
            if(!seen[y]){
                q.push(y);
                seen[y]=true;
            }
        }
        // cout<<endl;
    }
    cout<<mx+1<<endl;
}