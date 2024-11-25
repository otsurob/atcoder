#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using Graph = vector<vector<int>>;
using namespace std;

// 深さ優先探索
vector<bool> seen;  // 既に見たことがある頂点か記録
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next : G[v]) {
        if (!seen[next]) {  // 訪問済みでなければ探索
            dfs(G, next);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    int s, t;
    cin >> s >> t;

    Graph G(V);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back({b});
        // G[b].push_back({a});
    }

    seen.assign(V, false);  // 初期化
    dfs(G, s);
    if (seen[t]) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}