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
#define pll pair<ll, ll>
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;



vector<vector<ll>> d={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// 木(全域木)：閉路を持たない　辺の数＝頂点数-1
// グラフ：閉路や自己ループを持ったりする


//※mex(数列内に現れていない最小の自然数)　->　数列内の数がどんなに大きくても、mexは配列の要素数Nよりも小さい　->　Nより大きいものは無視できる
//※環状になっている　->　つながっているすべての頂点の次数が2


//四角形のすべての角が180°未満 <=> 2頂点が対角線を隔てて反対側にある
//2頂点を通る直線の式(対角線の式)に頂点の座標を代入。その正負で判定
ll ax, ay, bx, by, cx, cy, dx, dy;
bool linea(ll tx, ll ty){
    return (double)(ty-ay)*(cx-ax)-(cy-ay)*(tx-ax)>0;
}

bool lineb(ll tx, ll ty){
    return (double)(ty-by)*(dx-bx)-(dy-by)*(tx-bx)>0;
}

//exitは0!!!
//exit(0) 

// gcd
ull gcd(ull x, ull y){
    if(y==0) return x;
    else return gcd(y, x%y);
}

ull lcm(ull x, ull y){
    return x/gcd(x, y)*y;
}

//x以下のx/yの答えを求める関数(負の数に対応)
ll mfloor(ll x, ll y){
    ll n=(x%y+y)%y;
    return (x-n)/y;
}

// 逆元
// aの逆元をbとすると
// (x/a)%mod==x*b%mod と表すことができ、mod計算から割り算を消すことができる
ll modinv(ll a, ll mod) {
	long long b = mod, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= mod;
	if (u < 0) u += mod;
	return u;
}

//繰り返し二乗法
ll repeat_pow(ll a, ll n, ll mod) {
    if (n == 0) return 1;
    if (n == 1) return a % mod;

    ll ret = repeat_pow(a, n / 2, mod) % mod;
    (ret *= ret) %= mod;
    if (n % 2 == 1) {
        (ret *= a) %= mod;
    }
    return ret%mod;
}


// 小数をstringで入力処理をし、llにキャスト
int main(){
    ll a;
    string b;
    string c;
    rep(i, b.length()){
        if(b[i]=='.') continue;
        c.push_back(b[i]);
    }
    ll d=stoi(c);

    // string to int (long long)
    a = stoi(b); // (stoll)


    //swap
    ll x, y;
    swap(x, y);

    //resize
    vector<int> v={1, 2, 3};
    v.resize(5);       //a=={1, 2, 3, 0, 0}
    v.resize(1);       //a=={1}
    v.resize(5, 10);   //a=={1, 2, 3, 10, 10}

    //範囲for文
    vector<int> vv;
    for(int x : vv){}

    //queue
    queue<int> q;
    q.push(10);
    int a = q.front();
    q.pop();

    // map
    map<ll, ll> mp;
    // mapをfor文で取り出すと、pair型になっている
    for(auto x : mp){
        cout<<x.fst<<" "<<x.snd<<endl;
    }

    //set
    set<ll> st;
    st.insert(10);
    if(st.find(10)!=st.end())   //検索
    //イテレータ
    auto itr1=st.begin(); //先頭のイテレータ
    auto itr2=st.end(); //末尾のイテレータ
    itr2--; //末尾の1つ先を参照しているので、デクリメント
    auto itr3=--st.end();
    auto itr4=st.rbegin(); //itr2==itr3==itr4

    cout<<*itr2<<endl; //内容を参照
    //*(--st.end()), *(st.begin())のような参照もできる


    //sort
    sort(v.begin(), v.end());
    sort(v.rbegin(), v.rend());

    //sortの基準を指定
    vector<string> s={"a", "abc", "asfghjk", "cfg", "f"};
    auto cmp =[&](string a, string b){  //文字列の長さでsortするための基準を指定したラムダ式
        return a.size() < b.size();
    };

    sort(s.begin(), s.end(), cmp);

    
    //permutation
    // 指定する配列(ここではp)の初期値は辞書順で最小のものとする
    // 初期値から辞書順に調べていくので、初期値が辞書順で最小でないと全探索できない
    vector<int> p={1,2,3};   //必ずp={1, 2, 3}  それ以外ではだめ
    do{
        rep(i, p.size()) cout<<p[i]<<endl;
    }while(next_permutation(p.begin(), p.end()));

    //lower_bound, upper_bound
    // ※末尾よりも大きい値(例えば下の例では10とか)を引数にすると、イテレータは右端を指すが、そのvalue(*Iter)の値がバグる。
    // クソデカい数をpush_backしておくといいかも
    v={1, 2, 3, 4, 5, 6, 7};
    auto Iter = lower_bound(v.begin(), v.end(), 4); //4以上のものを二分探索   upper_boundは4より大きいものになる
    cout<<*Iter<<endl; //4 値を表示
    cout<<Iter - v.begin()<<endl; //3 先頭からの距離
    //↑同値↓
    ll Iter2 = lower_bound(v.begin(), v.end(), 4)-v.begin();
    // vector<pll> ab;
    // ab.push_back(pll(1, 2));
    // auto f=[&](ll i, ll j){
    //     auto [ai, aj] = ab[0];  //<-???
    //     return ai*i>aj*j;
    // };


    // 重複した要素の削除
    vector<ll> vec={1, 2, 2, 7, 5, 4, 4, 8, 3, 7, 3, 8};
    sort(vec.begin(), vec.end());
    //uniqueにより、重複した要素を削除したあとの配列の末尾のポインタを返す
    // eraseによってそのポインタから元の配列の末尾までを削除(残ったゴミを削除する処理)
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

    //数字かどうか判定
    if(isdigit('0')) cout<<'0'<<endl;

    //三項演算子
    ll a=5;
    ll NUM = a>=3 ? 5 : 2;
    //↑同値↓
    if(a>=3)NUM=5;
    else NUM=2;
}




// ※英子文字を操作する問題はサイズ26の配列を作って整数として処理