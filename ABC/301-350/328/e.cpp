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
    ll n, m, k;
    cin>>n>>m>>k;
    vector<ll> u(m), v(m), w(m);
    rep(i, m){
        cin>>u[i]>>v[i]>>w[i];
        u[i]--, v[i]--;
    }
    vector<ll> per;
    rep(i, n-1)per.push_back(0);
    while(per.size()<m)per.push_back(1);
    ll mn=9999999999999999;
    vector<vector<ll>> g(n);
    // vector<bool> seen(n, false);
    // ll cnt=0;
    do{
        // cnt++;
        // rep(i, per.size())cout<<per[i]<<" ";
        // cout<<endl;
        ll ns=0;
        rep(i, n)g[i]={};
        vector<bool> seen(n, false);
        rep(i, per.size()){
            if(per[i]==0){
                g[u[i]].push_back(v[i]);
                g[v[i]].push_back(u[i]);
                ns+=w[i];
                ns%=k;
            }
        }
        bool flag=true;
        queue<ll> q;
        q.push(0);
        seen[0]=true;
        while(!q.empty()){
            ll z=q.front();
            q.pop();
            for(auto x : g[z]){
                if(seen[x])continue;
                q.push(x);
                seen[x]=true;
            }
        }
        // rep(i, n)cout<<seen[i]<<" ";
        // cout<<endl;
        rep(i, n)if(!seen[i])flag=false;
        if(flag){
            mn=min(mn, ns);
        }
    }while(next_permutation(per.begin(), per.end()));
    cout<<mn%k<<endl;
    // cout<<cnt<<endl;
}