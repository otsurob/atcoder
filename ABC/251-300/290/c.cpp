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

int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    cinv(a, n);
    sort(a.begin(), a.end());
    // 重複した要素の削除
    //uniqueにより、重複した要素を削除したあとの配列の末尾のポインタを返す
    // eraseによってそのポインタから元の配列の末尾までを削除(残ったゴミを削除する処理)
	a.erase(unique(a.begin(), a.end()), a.end());
    rep(i, a.size()){
        if(i==k){
            cout<<i<<endl;
            return 0;
        }
        if(i!=a[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<a[a.size()-1]+1<<endl;
}