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

int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> ans(n, vector<ll>(n, 0));
    ll f=0;
    vector<vector<ll>> d={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    ll cnt=1, i=0, j=0;
    while(cnt<n*n){
        ans[i][j]=cnt;
        cnt++;
        if(i+d[f][0]<0 or i+d[f][0]>=n or j+d[f][1]<0 or j+d[f][1]>=n) f=(f+1)%4;
        if(ans[i+d[f][0]][j+d[f][1]]!=0) f=(f+1)%4;
        i+=d[f][0];
        j+=d[f][1];
    }
    rep(k, n){
        rep(l, n){
            if(ans[k][l]==0) cout<<'T'<<" ";
            else cout<<ans[k][l]<<" ";
        }
        cout<<endl;
    }
}