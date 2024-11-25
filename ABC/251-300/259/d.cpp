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
    ll n, sx, sy, tx, ty;
    cin>>n>>sx>>sy>>tx>>ty;
    vector<ll> x(n), y(n), r(n);
    vector<vector<ll>> g(n);
    ll sta=-1, gl=-1;
    rep(i, n)cin>>x[i]>>y[i]>>r[i];
    rep(i, n)rep2(i+1, j, n){
        if(((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))<=(r[i]+r[j])*(r[i]+r[j]) and ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))>=(r[i]-r[j])*(r[i]-r[j])){
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
    rep(i, n){
        if(((x[i]-sx)*(x[i]-sx)+(y[i]-sy)*(y[i]-sy))==r[i]*r[i])sta=i;
        if(((x[i]-tx)*(x[i]-tx)+(y[i]-ty)*(y[i]-ty))==r[i]*r[i])gl=i;
    }
    // coc2(sta, gl)
    if(sta==gl){
        couty()
        return 0;
    }
    if(sta==-1 or gl==-1){
        coutn()
        return 0;
    }
    // rep(i, n){
    //     for(auto k : g[i]){
    //         cout<<k<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<bool> seen(n, false);
    queue<ll> q;
    q.push(sta);
    seen[sta]=true;
    while(!q.empty()){
        ll m=q.front();
        q.pop();
        for(auto z : g[m]){
            if(z==gl){
                couty()
                return 0;
            }
            if(!seen[z]){
                seen[z]=true;
                q.push(z);
            }
        }
    }
    coutn()
}