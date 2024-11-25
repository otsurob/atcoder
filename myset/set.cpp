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
int main(){
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

    // lower_bound
    // set 用の2分探索が存在
    st.insert(3);
    st.insert(6);
    st.insert(9);
    auto it = st.lower_bound(5); //1番目のイテレータ
    cout<<*it<<endl; //6
}