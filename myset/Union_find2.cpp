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


//サイズを返す関数を実装

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


//グラフ内の閉路の数え上げ

int main(){
    ll n, m;
    cin>>n>>m;
    UnionFind tree(n);
    ll a, b;
    ll cnt=0;
    rep(i, m){
        cin>>a>>b;
        a--, b--;
        if(tree.root(a)==tree.root(b)) cnt++;
        tree.unite(a, b);
    }
    cout<<cnt<<endl;
}