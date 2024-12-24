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

vector<bool> Eratosthenes(int N) {
    // テーブル
    vector<bool> isprime(N+1, true);
    
    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;

    // ふるい
    rep2(2, p, N+1) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

int main(){
    ll n;
    cin>>n;
    ll x=0;
    if(n<4){
        cout<<0<<endl;
        return 0;
    }
    while(x*x<=n){
        x++;
    }
    x--;
    // エラトステネスの篩
    vector<bool> isprime = Eratosthenes(x);

    // 答え
    int res = 0;
    vector<ll> p;
    for (int i = 2; i <= x; ++i) {
        if (isprime[i]) p.push_back(i);
    }
    ll cnt=0;
    rep(i, p.size()-1){
        rep2(i+1, j, p.size()){
            if(p[i]*p[j]<=x)cnt++;
            else break;
        }
    }
    rep(i, p.size()){
        if(p[i]*p[i]*p[i]*p[i]<=x)cnt++;
        else break;
    }
    cout<<cnt<<endl;
}