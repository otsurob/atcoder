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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll n, x, ans=0;
vector<vector<ll>> nv;


void dfs(ll loopnum, ll pro){     //loopnumで"深さ"を管理
    if(loopnum==n){       //底にきたら終了
        if(pro==x) ans++;
        return;
    }
    for(ll m : nv[loopnum]){   //横方向のloopは範囲for文で処理
        if(pro>x) continue;
        dfs(loopnum+1, pro*m);   //再帰で深さ優先
    }
}

int main(){
    cin>>n>>x;
    nv.resize(n);    //nが入力されてから配列のサイズを決定
    vector<ll> l(n);
    rep(i, n){
        cin>>l[i];
        // wow();
        nv[i].resize(l[i]);
        // wow();
        rep(j, l[i]) cin>>nv[i][j];
    }
    // wow();
    dfs(0, 1);
    cout<<ans<<endl;
}