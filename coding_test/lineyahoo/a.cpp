#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;
int main(){
    ll n, m, q;
    cin>>n>>m>>q;
    vector<ll> s(q), t(q), x(q);
    rep(i, q)cin>>s[i]>>t[i]>>x[i];
    vector<vector<vector<vector<vector<ll>>>>> seen(n);
    rep(i, n)seen[i].resize(m);
    rep(i, n)rep(j, m)seen[i][j].resize(7);
    rep(i, n)rep(j, m)rep(k, 7)seen[i][j][k].resize(7);
    rep(i, n)rep(j, m)rep(k, 7)rep(l, 7)seen[i][j][k][l].resize(7);
    map<vector<ll>, bool> ng;
    rep(i, q)ng[{s[i], t[i], x[i]}]=true;
    queue<vector<ll>> qv;
    qv.push({0, 0, 1, 2, 4, 0});
    vector<vector<ll>> d={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    seen[0][0][1][2][4]=true;
    while(!qv.empty()){
        vector<ll> v=qv.front();
        qv.pop();
        ll now_y=v[0], now_x=v[1], up=v[2], south=v[3], east=v[4], cost=v[5];
        if(now_y==n-1 and now_x==m-1){
            cout<<"YES"<<endl;
            cout<<cost<<endl;
            return 0;
        }
        rep(i, 4){
            ll next_y=now_y+d[i][0], next_x=now_x+d[i][1];
            if(next_y<0 or next_y>=n or next_x<0 or next_x>=m)continue;
            ll next_up, next_south, next_east;
            if(i==0)next_up=7-south, next_south=up, next_east=east;
            if(i==1)next_up=south, next_south=7-up, next_east=east;
            if(i==2)next_up=7-east, next_south=south, next_east=up;
            if(i==3)next_up=east, next_south=south, next_east=7-up;
            if(ng[{next_y, next_x, next_up}] or seen[next_y][next_x][next_up][next_south][next_east])continue;
            seen[next_y][next_x][next_up][next_south][next_east]=true;
            qv.push({next_y, next_x, next_up, next_south, next_east, cost+1});
        }
    }
    cout<<"NO"<<endl;
}