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

// 指定した数値以上のもののうち、一番小さいものを返す　(数値を挿入するときの位置と同値)
// upperは数値より大きいになる

int main(){
    // ※末尾よりも大きい値(例えば下の例では10とか)を引数にすると、イテレータは右端を指すが、そのvalue(*Iter)の値がバグる。
    // クソデカい数をpush_backしておくといいかも
    vector<ll> v={1, 2, 3, 4, 5, 6, 7};
    auto Iter = lower_bound(v.begin(), v.end(), 4); //4以上のものを二分探索   upper_boundは4より大きいものになる
    cout<<*Iter<<endl; //4 値を表示
    cout<<Iter - v.begin()<<endl; //3 先頭からの距離
    //↑同値↓
    ll Iter2 = lower_bound(v.begin(), v.end(), 4)-v.begin();
}