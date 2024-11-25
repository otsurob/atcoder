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
    ll h, w, n, y, x;
    cin>>h>>w>>n>>y>>x;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, h)rep(j, w)cin>>a[i][j];
    vector<ll> cnt(n+1, 0), tmp;
    // wow()
    rep(i, h)rep(j, w)cnt[a[i][j]]++;
    vector<set<ll>> st(h);
    vector<vector<ll>> tc(h, vector<ll>(n+1, 0));

    vector<vector<ll>> ans(h-y+1, vector<ll>(w-x+1, 0));
    // wow()
    tc[0]=cnt;
    rep(i, y)rep(j, x)tc[0][a[i][j]]--;
    rep(i, n+1)if(tc[0][i]>0)st[0].insert(i);
    ans[0][0]=st[0].size();
    rep2(1, i, h-y+1){
        tc[i]=tc[i-1];
        rep(k, x){
            tc[i][a[i-1][k]]++;
            tc[i][a[i-1+y][k]]--;
        }
        rep(k, n+1)if(tc[i][k]>0)st[i].insert(k);
        ans[i][0]=st[i].size();
    }
    // wow()
    rep(i, h-y+1){
        // tc[i]=tc[i-1];
        // rep(k, x){
        //     tc[i][a[i-1][k]]++;
        //     tc[i][a[i-1+y][k]]--;
        // }
        // rep(k, n+1)if(tc[i][k]>0)st[i].insert(k);
        // ans[i][0]=st[i].size();
        rep2(1, j, w-x+1){
            rep(l, y){
                if(tc[i][a[i+l][j-1]]==0)st[i].insert(a[i+l][j-1]);
                tc[i][a[i+l][j-1]]++;
                tc[i][a[i+l][j-1+x]]--;
                if(tc[i][a[i+l][j-1+x]]==0)st[i].erase(a[i+l][j-1+x]);
            }
            ans[i][j]=st[i].size();
        }
    }
    // wow()
    rep(i, h-y+1){
        rep(j, w-x+1){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}