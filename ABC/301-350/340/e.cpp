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


/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    update(a,b,x): 区間[a,b) の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
*/
template <typename T>
struct RSUM {
    const T INF = 0;
    ll n;
    vector<T> dat, lazy;
    RSUM(ll n_){
        ll x = 1;
        while (n_ > x) x *= 2;
        n = x;
        dat.resize(n*2-1);
        lazy.resize(n*2-1);
    }

    void init(vector<ll> a){
        rep(i, a.size()){
            dat[i+n-1]=a[i];
        }
    }
    // この構造体内ではnは完全二分木の大きさ (配列の倍)
    ll task(ll k){
        vector<ll> line={};
        ll x = k+n-1;
        line.push_back(x);
        while(x>0){
            line.push_back(x);
            x = (x-1)/2;
        }
        while(!line.empty()){
            eval(line.back());
            line.pop_back();
        }
        ll m=dat[k+n-1];
        dat[k+n-1]=0;
        return m;
    }


    /* lazy eval */
    void eval(ll k) {
        if (lazy[k] == INF) return;  // 更新するものが無ければ終了
        if (k < n - 1) {             // 葉でなければ子に伝搬
            lazy[k * 2 + 1] += lazy[k];
            lazy[k * 2 + 2] += lazy[k];
        }
        // 自身を更新
        dat[k] += lazy[k];
        lazy[k] = INF;
    }

    void update_sub(ll a, ll b, ll x, ll k, ll l, ll r) {
        // coc4(a, b, l, r)
        eval(k);
        if(b<=l || r<=a) return;
        if (a <= l && r <= b) {  // 完全に内側の時
            // wow()
            lazy[k] += x;
            eval(k);
        } else {                     // 一部区間が被る時
            update_sub(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update_sub(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            // dat[k]=dat[2*k+1]+dat[2*k+2];
        }
    }
    void update(ll a, ll b, ll x) { update_sub(a, b, x, 0, 0, n); }

    // T query_sub(ll a, ll b, ll k, ll l, ll r) {
    //     eval(k);
    //     if (r <= a || b <= l) {  // 完全に外側の時
    //         return INF;
    //     } else if (a <= l && r <= b) {  // 完全に内側の時
    //         return dat[k];
    //     } else {  // 一部区間が被る時
    //         T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
    //         T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
    //         return min(vl, vr);
    //     }
    // }
    // T query(ll a, ll b) { return query_sub(a, b, 0, 0, n); }

    /* debug */
    // inline T operator[](ll a) { return query(a, a + 1); }
    void finish(){
        rep(i, 2*n-1)eval(i);
    }
    void print(ll x) {
        rep2(n-1, i, n-1+x)cout<<dat[i]<<" ";
        codl()
    }

    void debug(){
        rep(i, 2*n-1)cout<<dat[i]<<" ";
        codl();
        rep(i, 2*n-1)cout<<lazy[i]<<" ";
        codl();
    }
};


int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll> a(n), b(m);
    cinv(a, n);
    cinv(b, m);

    RSUM<ll> seg(n);
    seg.init(a);
    // seg.print();

    rep(i, m){
        ll x = seg.task(b[i]);
        // cout<<"#"<<x<<endl;
        ll p=0, cnt=1;
        if(x>n){
            p = x%n;
            cnt=x/n;
            if(b[i]==n-1){
                seg.update(0, p, 1);
            }
            else if(b[i]+p>=n){
                ll y=b[i]+p-n;
                seg.update(b[i]+1, n, 1);
                seg.update(0, y+1, 1);
            }else{
                seg.update(b[i]+1, b[i]+p+1, 1);
            }
            seg.update(0, n, cnt);
        }
        else{
            if(b[i]==n-1){
                seg.update(0, x, 1);
            }
            else if(b[i]+x>=n){
                ll y=b[i]+x-n;
                seg.update(b[i]+1, n, 1);
                seg.update(0, y+1, 1);
            }else{
                seg.update(b[i]+1, b[i]+x+1, 1);
            }
        }
        // seg.debug();
        // seg.print();
    }
    seg.finish();
    seg.print(n);
}