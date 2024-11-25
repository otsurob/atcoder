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
    ll n, m;
    cin>>n>>m;
    vector<ll> a(m), b(m);
    cinv(a, m);
    cinv(b, m);
    vector<vector<ll>> g(n);
    rep(i, m){
        if(a[i]==b[i]){
            coutn()
            return 0;
        }
        g[a[i]-1].push_back(b[i]-1);
        g[b[i]-1].push_back(a[i]-1);
    }
    vector<ll> x(n, -1);
    queue<ll> q;
    rep(i, n){
        if(x[i]==-1){
            x[i]=0;
            q.push(i);
        }
        // coc(i)
        while(!q.empty()){
            ll y=q.front();
            q.pop();
            ll z=x[y]^1;
            for(auto k : g[y]){
                // coc2(y, k)
                if(x[k]==-1){
                    q.push(k);
                    x[k]=z;
                }else if(x[k]!=z){
                    // coc4(y, k, x[y], x[k])
                    coutn()
                    return 0;
                }
            }
        }
    }
    couty()
}