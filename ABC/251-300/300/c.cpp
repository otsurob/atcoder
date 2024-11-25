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
    int h, w;
    cin>>h>>w;
    vector<vector<char>> c(h, vector<char> (w));
    rep(i, h) rep(j, w) cin>>c[i][j];
    vector<vector<bool>> seen(h, vector<bool> (w, false));
    int mn = min(h, w);
    vector<int> ans(mn, 0);
    rep(i, h) rep(j, w){
        // cout<<i<<j<<endl;
        if(c[i][j]=='#' and seen[i][j]==false){
            int count=0, k=i, l=j;
            while(k<h and l<w and c[k][l]=='#'){
                count++;
                k++;
                l++;
            }
            // cout<<count<<endl;
            int sz=count/2;
            int mid1 = i+sz, mid2=j+sz;
            // seen[mid1][mid2]==true;
            rep(n, sz+1){
                seen[mid1+n][mid2+n]=true;
                seen[mid1+n][mid2-n]=true;
                seen[mid1-n][mid2+n]=true;
                seen[mid1-n][mid2-n]=true;
            }
            // cout<<sz<<endl;
            ans[sz-1]++;
        }
    }
    rep(i, mn) cout<<ans[i]<<" ";
    cout<<endl;
}
