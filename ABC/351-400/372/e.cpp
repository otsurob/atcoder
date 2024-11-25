#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<' ';
#define codl() cout<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
#define decout(a) cout<<fixed<<setprecision(15)<<a<<endl;
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
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    
    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }
    
    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }
    
    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
    ll n, q;
    cin>>n>>q;
    vector<vector<ll>> g(n);
    rep(i, n)g[i].push_back(i);
    UnionFind tree(n);
    vector<ll> ans;
    while(q--){
        ll m, u, v, k;
        cin>>m;
        if(m==1){
            cin>>u>>v;
            u--, v--;
            ll uu=tree.root(u), vv=tree.root(v);
            tree.unite(u, v);
            for(ll z : g[uu])g[vv].push_back(z);
            sort(g[vv].rbegin(), g[vv].rend());
        	g[vv].erase(unique(g[vv].begin(), g[vv].end()), g[vv].end());
            vector<ll> tmp={};
            ll szz = g[vv].size();
            ll sz=min(10ll, szz);
            rep(j, sz){
                tmp.push_back(g[vv][j]);
            }
            g[vv]=tmp;
        }
        else{
            cin>>v>>k;
            v--, k--;
            ll vvv = tree.root(v);
            if(g[vvv].size()<=k){
                // cout<<-1<<endl;
                ans.push_back(-1);
            }
            else{
                // cout<<g[v][k]<<endl;
                ans.push_back(g[vvv][k]+1);
            }
        }
    }
    // codl()
    // rep(i, n){
    //     cout<<tree.root(i)<<endl;
    //     for(ll te : g[i])cout<<te<<" ";
    //     codl();
    //     codl();
    // }
    rep(i, ans.size())cout<<ans[i]<<endl;
}