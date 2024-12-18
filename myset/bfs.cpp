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

using namespace std;
const int inf = 1000000010;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
    int n;
    cin >> n;
    vector<vector<char>> s(n, vector<char>(n));
    rep(i, n) rep(j, n) cin >> s[i][j];
    vector<vector<vector<vector<int>>>> dis(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, inf))));
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    rep(i, n) rep(j, n) if (s[i][j] == 'P') {
        if (x1 == -1) x1 = i, y1 = j;
        else x2 = i, y2 = j;
    }
    queue<array<int, 4>> que;
    // 初期地点からの距離
    dis[x1][y1][x2][y2] = 0;

    que.push({ x1,y1,x2,y2 });
    while (!que.empty()) {
        array<int, 4> ar = que.front(); 
        que.pop();
        rep(d, 4) {
            array<int, 4> nxt = ar;
            nxt[0] += dx[d], nxt[1] += dy[d];
            if (0 > nxt[0] or nxt[0] >= n or 0 > nxt[1] or nxt[1] >= n or s[nxt[0]][nxt[1]] == '#') {
                nxt[0] = ar[0], nxt[1] = ar[1];
            }
            nxt[2] += dx[d], nxt[3] += dy[d];
            if (0 > nxt[2] or nxt[2] >= n or 0 > nxt[3] or nxt[3] >= n or s[nxt[2]][nxt[3]] == '#') {
                nxt[2] = ar[2], nxt[3] = ar[3];
            }
            // nxtが初期値==未探索とし、さらに初期地点からの距離も同時に記録
            if (dis[nxt[0]][nxt[1]][nxt[2]][nxt[3]] == inf) {
                dis[nxt[0]][nxt[1]][nxt[2]][nxt[3]] = dis[ar[0]][ar[1]][ar[2]][ar[3]] + 1;
                que.push(nxt);
            }
        }
    }
    int ans = inf;
    rep(i, n) rep(j, n) ans = min(ans, dis[i][j][i][j]);
    cout << (ans == inf ? -1 : ans) << '\n';
}