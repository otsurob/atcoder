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


struct UnionFind {
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    
    UnionFind(ll N) : par(N) { //最初は全てが根であるとして初期化
        for(ll i = 0; i < N; i++) par[i] = i;
    }
    
    ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(ll x, ll y) { // xとyの木を併合
        ll rx = root(x); //xの根をrx
        ll ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }
    
    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};


int main(){
    ll h, w, q;
    cin>>h>>w>>q;
    vector<string> ans={};
    vector<vector<ll>> d={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    ll n=h*w;
    // coc(n)
    UnionFind tree(n);
    vector<vector<bool>> f(h, vector<bool>(w, false));
    while(q--){
        ll t;
        cin>>t;
        if(t==1){
            ll r, c;
            cin>>r>>c;
            r--, c--;
            f[r][c]=true;
            rep(i, 4){
                ll ny=r+d[i][0], nx=c+d[i][1];
                // coc2(r*h+c, ny*h+nx);
                if(0<=ny and ny<h and 0<=nx and nx<w and f[ny][nx]){
                    // wow()
                    // if(tree.same(r*w+c, ny*w+nx))wow()
                    tree.unite(r*w+c, ny*w+nx);
                }
            }
        }else{
            ll ra, ca, rb, cb;
            cin>>ra>>ca>>rb>>cb;
            ra--, ca--, rb--, cb--;
            if(f[ra][ca] and f[rb][cb]){
                if(tree.same(ra*w+ca, rb*w+cb))ans.push_back("Yes");
                else ans.push_back("No");
            }else ans.push_back("No");
        }
    }
    rep(i, ans.size())cout<<ans[i]<<endl;
}