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
    ll n, t;
    cin>>n>>t;
    vector<ll> a(t);
    cinv(a, t);
    vector<ll> yc(n, 0), tc(n, 0), nc(2, 0);
    vector<vector<bool>> seen(n, vector<bool>(n, false));
    rep(i, t){
        ll ii=(a[i]-1)/n, jj=(a[i]-1)%n;
        if(!seen[ii][jj]){
            seen[ii][jj]=true;
            yc[ii]++;
            tc[jj]++;
            if(ii+jj==n-1)nc[0]++;
            if(ii==jj)nc[1]++;
            if(yc[ii]==n or tc[jj]==n or nc[0]==n or nc[1]==n){
                cout<<i+1<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}