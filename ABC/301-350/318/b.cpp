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
    int n;
    cin>>n;
    int a, b, c, d;
    vector<vector<bool>> g(109, vector<bool> (109, false));
    rep(i, n){
        cin>>a>>b>>c>>d;
        rep2(a, j, b) rep2(c, k, d) g[j][k]=true;
    }
    int count=0;
    rep(i, 109) rep(j, 109) if(g[i][j]) count++;
    cout<<count<<endl;
}