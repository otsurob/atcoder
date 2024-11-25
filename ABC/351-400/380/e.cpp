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


struct UnionFind {
    vector<vector<int>> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    
    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化(サイズは1なので-1で初期化する)
        for(int i = 0; i < N; i++) par[i] = {-1, i, i};
    }
    
    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x][0] < 0) return x; //サイズ(負の値)が格納されている==根である
        return par[x][0] = root(par[x][0]);
    }
    
    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま

        if(par[rx] > par[ry]) swap(rx, ry); //サイズが大きいほうに併合するための処理(サイズは負の値として入っているから)
        par[rx][0] += par[ry][0]; //xのサイズにyのサイズを加算
        par[ry][0] = rx; //yの根をxに更新する
        par[rx][1] = min(par[ry][1], par[rx][1]);
        // par[ry][2] = -1; //yの根をxに更新する
    }
    
    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x){
        return -par[root(x)][0]; //サイズは負の値として入っているため
    }

    void ccolor(int x, int c){
        par[root(x)][2] = c;
    }

    int gcolor(int x){
        return par[root(x)][2];
    }

    int gmin(int x){
        return par[root(x)][1];
    }

    int gmax(int x){
        return par[root(x)][1];
    }
};



int main(){
    ll n, q;
    cin>>n>>q;
    UnionFind tree(n);
    vector<ll> cnt(n, 1);
    vector<ll> ans;
    while(q--){
        ll p;
        cin>>p;
        if(p==1){
            ll x, c;
            cin>>x>>c;
            x--, c--;
            ll pc=tree.gcolor(x);
            ll sz=tree.size(x);
            // wow()
            cnt[pc]-=sz;
            tree.ccolor(x, c);
            cnt[c]+=sz;
            ll mn=tree.gmin(x), mx=tree.gmin(x) + tree.size(x)-1;
            // wow()
            // coc2(mn, mx)
            if(mn!=0 and tree.gcolor(mn-1)==tree.gcolor(x)){
                tree.unite(mn-1, x);
            }
            if(mx!=n-1 and tree.gcolor(mx+1)==tree.gcolor(x)){
                tree.unite(mx+1, x);
            }
        }else{
            ll c;
            cin>>c;
            c--;
            // ans.push_back(cnt[c]);
            cout<<cnt[c]<<endl;
        }
    }
    // coutv(ans, ans.size());
    // codl()
}