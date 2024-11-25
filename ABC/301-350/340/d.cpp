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

// int main(){
//     ll n;
//     cin>>n;
//     vector<vector<ll>> vv;
//     vector<ll> a(n-1), b(n-1), x(n-1);
//     rep(i, n-1){
//         cin>>a[i]>>b[i]>>x[i];
//         vv.push_back({x[i], b[i], i});
//     }
//     vector<ll> dp(n, 9999999999999);
//     dp[0]=0;
//     rep(i, n-1){
//         dp[i+1]=min(dp[i+1], dp[i]+a[i]);
//         dp[x[i]-1]=min(dp[x[i]-1], dp[i]+b[i]);
//     }
//     sort(vv.begin(), vv.end());
//     for(auto z : vv){
//         dp[z[0]-1]=min(dp[z[0]-1], dp[z[2]]+z[1]);
//         cout<<dp[z[0]-1]<<endl;
//         // wow();
//     }
//     cout<<dp[n-1]<<endl;
// }

int main(){
    ll n, a, b, x;
    cin>>n;
    vector<vector<pair<ll, ll>>> p(n-1);
    rep(i, n-1){
        cin>>a>>b>>x;
        x--;
        // 行き先とコストのペアを追加
        p[i].push_back(pair<ll, ll>(i+1, a));
        p[i].push_back(pair<ll, ll>(x, b));
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(pair<ll, ll>(0, 0));
    ll fc = numeric_limits<ll>::max();
    vector<ll> cost(n, fc);
    cost[0]=0;
    while(!pq.empty()){
        pair<ll, ll> tmp = pq.top();
        // コストで優先探索したいので、コストを一つ目に置く
        ll c = tmp.first;
        ll s = tmp.second;
        cout<<s<<endl;
        pq.pop();
        // ゴール処理
        if(s==n-1){
            cout<<cost[s]<<endl;
            return 0;
        }
        if(cost[s]<c) continue; //訪問時のコストが今よりも低いなら探索しない
        rep(i, p[s].size()){
            ll next = p[s][i].first;
            ll nxc = p[s][i].second+c;
            if(cost[next]<=nxc) continue;
            pq.push(pair<ll, ll>(nxc, next));
            cost[next]=nxc;
        }
    }
}