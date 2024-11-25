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

int main(){
    int h, w, n;
    cin>>h>>w>>n;
    int x=0, y=0;
    int mc=0;
    vector<vector<int>> mov={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<char>> grid(h, vector<char>(w, '.'));
    rep(i, n){
        if(x<0) x+=w;
        else if(x>=w) x-=w;
        if(y<0) y+=h;
        else if(y>=h) y-=h;
        if(grid[y][x]=='.'){
            grid[y][x]='#';
            mc++;
        }else{
            grid[y][x]='.';
            mc--;
        }
        y+=mov[mc%4][0];
        x+=mov[mc%4][1];
    }
    rep(i, h){
        rep(j, w){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}