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
    ll n;
    cin>>n;
    vector<ll> a(n);
    cinv(a, n);
    vector<string> s(n);
    cinv(s, n);
    ll q;
    cin>>q;
    vector<ll> u(q), v(q);
    rep(i, q){
        cin>>u[i]>>v[i];
        u[i]--, v[i]--;
    }
    ll inf=9999999999999999;
    vector<vector<ll>> d(n, vector<ll>(n, inf));
    vector<vector<ll>> score(n, vector<ll>(n, 0));
    vector<vector<ll>> g(n);
    rep(i, n){
        rep(j, n){
            if(i==j){
                d[i][j]=0;
                score[i][j]=a[i];
            }
            else if(s[i][j]=='Y'){
                d[i][j]=1;
                score[i][j]=a[i]+a[j];
            }
        }
    }
    for (int k = 0; k < n; k++){       // 経由する頂点
        for (int i = 0; i < n; i++) {    // 始点
            for (int j = 0; j < n; j++) {  // 終点
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    score[i][j] = score[i][k]+score[k][j]-a[k];
                }else if(d[i][k]+d[k][j]==d[i][j] and score[i][k]+score[k][j]-a[k]>score[i][j]){
                    score[i][j]=score[i][k]+score[k][j]-a[k];
                }
            }
        }
    }
    rep(i, q){
        if(d[u[i]][v[i]]==inf)cout<<"Impossible"<<endl;
        else cout<<d[u[i]][v[i]]<<" "<<score[u[i]][v[i]]<<endl;
    }

}