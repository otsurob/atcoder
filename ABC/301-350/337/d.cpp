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
    ll h, w, k;
    cin>>h>>w>>k;
    vector<string> s(h);
    cinv(s, h)
    vector<vector<ll>> sc1(h, vector<ll>(w+1, 0)), sc2(w, vector<ll>(h+1, 0)), dc1(h, vector<ll>(w+1, 0)), dc2(w, vector<ll>(h+1, 0)), cc1(h, vector<ll>(w+1, 0)), cc2(w, vector<ll>(h+1, 0));
    // if(s[0][0]=='o'){
    //     sc1[0][0]++;
    //     sc2[0][0]++;
    // }else if(s[0][0]=='.'){
    //     dc1[0][0]++;
    //     dc2[0][0]++;
    // }else{
    //     cc1[0][0]++;
    //     cc2[0][0]++;
    // }
    rep(i, h)rep2(1, j, w+1){
        sc1[i][j]+=sc1[i][j-1];
        dc1[i][j]+=dc1[i][j-1];
        cc1[i][j]+=cc1[i][j-1];
    if(s[i][j-1]=='o') sc1[i][j]++;
    else if(s[i][j-1]=='.') dc1[i][j]++;
    else cc1[i][j]++;
    // coc(cc1[i][j]);
    }
    rep(i, w)rep2(1, j, h+1){
        sc2[i][j]+=sc2[i][j-1];
        dc2[i][j]+=dc2[i][j-1];
        cc2[i][j]+=cc2[i][j-1];
    if(s[j-1][i]=='o') sc2[i][j]++;
    else if(s[j-1][i]=='.') dc2[i][j]++;
    else cc2[i][j]++;
    }
    ll mn=9999999999;
    // wow()
    if(w-k>=0){
        rep(i, h){
            rep2(k-1, j, w){
                // coc4(cc1[i][j+1], cc1[i][j-k+1], dc1[i][j+1], dc1[i][j-k+1])
                if(cc1[i][j+1]-cc1[i][j-k+1]==0){
                    mn=min(mn, dc1[i][j+1]-dc1[i][j-k+1]);
                }
            }
        }
    }
    // wow()
    if(h-k>=0){
        rep(i, w)rep2(k-1, j, h){
        // coc4(cc2[j+1][i], cc2[j-k+1][i], dc2[j+1][i], dc2[j-k+1][i])
            if(cc2[i][j+1]-cc2[i][j-k+1]==0) mn=min(mn, dc2[i][j+1]-dc2[i][j-k+1]);
        }
    }

    if(mn!=9999999999)cout<<mn<<endl;
    else cout<<-1<<endl;
}