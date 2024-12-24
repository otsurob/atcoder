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
#define inf 999999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

ll n, m;
ll cnt=0;

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

        if(ry>=n and rx<n)swap(rx, ry);
        else if(par[rx] > par[ry]) swap(rx, ry); //サイズが大きいほうに併合するための処理(サイズは負の値として入っているから)
        
        if(rx>=n and ry<n)cnt-=par[ry];
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
    ll e;
    cin>>n>>m>>e;
    vector<ll> u(e), v(e);
    rep(i, e){
        cin>>u[i]>>v[i];
        u[i]--, v[i]--;
    }
    ll q;
    cin>>q;
    vector<ll> x(q);
    cinv(x, q);
    rep(i, q)x[i]--;
    UnionFind tree(n+m);
    set<ll> xx;
    rep(i, q)xx.insert(x[i]);
    rep(i, e){
        if(xx.find(i)!=xx.end())continue;
        tree.unite(u[i], v[i]);
    }
    vector<ll> ans;
    ans.push_back(cnt);
    rrep(i, q){
        tree.unite(u[x[i]], v[x[i]]);
        ans.push_back(cnt);
    }
    ans.pop_back();
    rrep(i, ans.size())cout<<ans[i]<<endl;
}