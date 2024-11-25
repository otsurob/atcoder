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
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    
    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化(サイズは1なので-1で初期化する)
        for(int i = 0; i < N; i++) par[i] = -1;
    }
    
    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] < 0) return x; //サイズ(負の値)が格納されている==根である
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま

        if(par[rx] > par[ry]) swap(rx, ry); //サイズが大きいほうに併合するための処理(サイズは負の値として入っているから)
        par[rx] += par[ry]; //xのサイズにyのサイズを加算
        par[ry] = rx; //yの根をxに更新する
    }
    
    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x){
        return -par[root(x)]; //サイズは負の値として入っているため
    }
};


int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> g(n);
    ll a, b;
    UnionFind tree(n);
    rep(i, m){
        cin>>a>>b;
        a--, b--;
        // g[a].push_back(b);
        // g[b].push_back(a);
        tree.unite(a, b);
    }
    ll sum=0;
    rep(i, n){
        ll s=tree.size(i);
        // coc(tree.par[i]);
        if(tree.par[i]>=-1) continue;
        if(tree.par[i]==-2){
            sum++;
            continue;
        }
        sum+=s*(s-1)/2;
        // coc(sum)
    }
    cout<<sum-m<<endl;

}