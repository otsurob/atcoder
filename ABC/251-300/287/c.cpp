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
    vector<vector<ll>> g(n);
    vector<ll> c(n, 0);
    ll u, v;
    rep(i, m){
        cin>>u>>v;
        u--, v--;
        c[u]++, c[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n!=m+1){
        coutn()
        return 0;
    }
    ll sta=-1;
    rep(i, n){
        if(c[i]==1){
            sta=i;
            break;
        }
    }
    if(sta==-1 or g[sta].size()!=1){
        coutn()
        return 0;
    }
    ll now=g[sta][0];
    ll cnt=1;
    while(cnt<n){
        if(g[now].size()==1){
            cnt++;
            break;
        }
        if(g[now].size()>2){
            coutn()
            return 0;
        }
        rep(i, 2){
            if(g[now][i]!=sta){
                sta=now;
                now=g[now][i];
                break;
            }
        }
        cnt++;
    }
    if(cnt==n) couty()
    else coutn()
}

// int main(){
//     ll n, m;
//     cin>>n>>m;
//     vector<ll> cnt(n, 0);
//     ll u, v;
//     rep(i, m){
//         cin>>u>>v;
//         u--, v--;
//         cnt[u]++, cnt[v]++;
//     }
//     ll c1=0, c2=0;
//     rep(i, n){
//         if(cnt[i]==1) c1++;
//         if(cnt[i]==2) c2++;
//     }
//     if(c1==2 and c2==n-2)couty()
//     else coutn()
// }