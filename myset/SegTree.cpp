// RMQ (区間の最小値を求めるセグメント木)

#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
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

static const int max_n = 1 << 15; //数列a_iの最大の要素数を設定する
ll seg_tree[2 * max_n];
ll n;

//初期化を行う関数
void init(ll n_) {
	//完全二分木にするため、データ数を2の倍数にする。
	n = 1;
	while (n < n_) n *= 2;

	//RMQを考えたいので、セグ木の各値はINT_MAXに設定しておく
	rep(i, 2 * n)seg_tree[i] = INT_MAX;
}

//index番目の値をxに変更する関数
void update(ll index, ll x) {
	index += n - 1; //最も下のレイヤーにおいて、1番目の値はseg_treeの中ではn番目だから
	seg_tree[index] = x;
	while (index > 0) {
		index = (index - 1) / 2; //親のノードのindex
		seg_tree[index] = min(seg_tree[2 * index + 1], seg_tree[2 * index + 2]);
	}
}


//query(a,b,0,0,n)として呼ぶことを考える。

//main関数ではこれを呼ぶ。　区間[a, b)
ll query(ll a, ll b){
	return query_sub(a, b, 0, 0, n);
}

//区間[a,b)における最小値を求める関数
//indexはseg_treeにおける番号で、left,rightはseg_tree[index]の区間に対応。　seg_tree[index] => [left, right)
ll query_sub(ll a, ll b, ll index, ll left, ll right) {
	//考えようとしている区間が、[a,b)に全く含まれないなら、INT_MAXを返して、操作に影響しないようにする。
	if (a >= right || b <= left) return INT_MAX;

	//考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
	if (a <= left && b >= right) return seg_tree[index];

	//どちらでもない場合、seg_tree[index]の2つの子ノードに対して再帰的に操作を行う。
	ll value_1 = query_sub(a, b, 2 * index + 1, left, (left + right) / 2);
	ll value_2 = query_sub(a, b, 2 * index + 2, (left + right) / 2, right);
	return min(value_1, value_2);
}
