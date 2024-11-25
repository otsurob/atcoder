#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

// vector<int> par(100), rk(100);
// void init(int n){
//     rep(i, n){
//         par[i]=i;
//         rk[i]=0;
//     }
// }

// int root(int x){
//     return par[x]==x ? x:par[x] = root(par[x]);
// }

// bool same(int x, int y){
//     return root(x)==root(y);
// }

// void unite(int x, int y){
//     x=root(x);
//     y=root(y);
//     if(x==y) return;

//     if(rk[x]<rk[y]){
//         par[x]=y;
//     }else{
//         par[y]=x;
//         if(rk[x]==rk[y]) rk[x]++;
//     }
// }


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
    int n, m;
    cin>>n>>m;
    if(m==0){
        coutn();
        return 0;
    }
    UnionFind tree(n);
    vector<int> u(m), v(m);
    vector<int> vv(n, 0), ev(n, 0);

    rep(i, m){
        cin>>u[i]>>v[i];
        u[i]--;
        v[i]--;
        tree.unite(u[i], v[i]);
    }

    rep(i, n) vv[tree.root(i)]++;
    rep(i, m) ev[tree.root(u[i])]++;
    
    if(vv==ev){
        couty();
    }else{
        coutn();
    }
}