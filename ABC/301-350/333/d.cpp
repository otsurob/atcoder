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
    ll n;
    cin>>n;
    vector<ll> sta;
    ll u, v;
    vector<vector<ll>> l(n);
    rep(i, n-1){
        cin>>u>>v;
        u--;
        v--;
        if(u==0) sta.push_back(v);
        l[u].push_back(v);
        l[v].push_back(u);
    }
    vector<bool> seen(n, false);
    ll mx=-1, sum=0;
    // vector<ll> ans;
    ll cnt;
    seen[0]=true;
    for(auto x : sta){
        queue<ll> q;
        q.push(x);
        seen[x]=true;
        cnt=1;
        while(!q.empty()){
            ll y=q.front();
            q.pop();
            for(auto z : l[y]){
                if(!seen[z]){
                    q.push(z);
                    seen[z]=true;
                    cnt++;
                }
            }
        }
        sum+=cnt;
        // ans.push_back(cnt);
        mx=max(mx, cnt);
    }
    cout<<sum-mx+1<<endl;
}