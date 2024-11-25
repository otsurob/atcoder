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
    ll n, m, k, q;
    cin>>n>>m;
    UnionFind tree(n);
    vector<ll> u(m), v(m);
    set<pll> st;
    rep(i, m){
        cin>>u[i]>>v[i];
        u[i]--, v[i]--;
        tree.unite(u[i], v[i]);
    }
    cin>>k;
    vector<ll> x(k), y(k);
    rep(i, k){
        cin>>x[i]>>y[i];
        x[i]--, y[i]--;
        st.insert(pll(tree.root(x[i]), tree.root(y[i])));
        st.insert(pll(tree.root(y[i]), tree.root(x[i])));
    }
    cin>>q;
    vector<ll> p(q), qq(q);
    rep(i, q){
        cin>>p[i]>>qq[i];
        p[i]--, qq[i]--;
    }
    rep(i, q){
        if(st.find(pll(tree.root(p[i]), tree.root(qq[i])))!=st.end())coutn()
        else couty()
    }
}