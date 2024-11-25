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

int main(){
    ll h1, h2, w1, w2;
    cin>>h1>>w1;
    vector<vector<ll>> a(h1, vector<ll>(w1));
    rep(j, h1) cinv(a[j], w1);
    cin>>h2>>w2;
    vector<vector<ll>> b(h2, vector<ll>(w2));
    rep(j, h2) cinv(b[j], w2);
    ll dh=h1-h2, dw=w1-w2;
    vector<ll> vh, vw;
    rep(i, h2)vh.push_back(0);
    rep(i, dh)vh.push_back(1);
    rep(i, w2)vw.push_back(0);
    rep(i, dw)vw.push_back(1);
    // rep(i, h1)cout<<vh[i]<<" ";
    // cout<<endl;
    // rep(i, w1)cout<<vw[i]<<" ";
    // cout<<endl;
    do{
        do{
            vector<vector<ll>> ans={};
            rep(i, h1){
                if(vh[i]==1)continue;
                vector<ll> tmp={};
                rep(j, w1){
                    if(vw[j]==0)tmp.push_back(a[i][j]);
                }
                ans.push_back(tmp);
            }
            // rep(i, ans.size()){
            //     rep(j, ans[i].size())cout<<ans[i][j]<<" ";
            //     cout<<endl;
            // }
            // cout<<endl;
            // cout<<ans.size();
            if(ans==b){
                couty()
                return 0;
            }
        }while(next_permutation(vw.begin(), vw.end()));
    }while(next_permutation(vh.begin(), vh.end()));
    coutn()
}