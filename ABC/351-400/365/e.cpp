#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<' ';
#define codl() cout<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
#define decout(a) cout<<fixed<<setprecision(15)<<a<<endl;
#define wow() cout<<"wow"<<endl;
#define coc(a) cout<<a<<endl;;
#define coc2(a, b) cout<<a<<" "<<b<<endl;
#define coc3(a, b, c) cout<<a<<" "<<b<<" "<<c<<endl;
#define coc4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define pll pair<ll, ll>
#define fst first
#define snd second
#define inf 9999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    cinv(a, n);
    vector<vector<ll>> x(30, vector<ll>(n, 0));
    rep(i, n){
        rep(j, 30){
            if(a[i]%2==1)x[j][i]=1;
            a[i]/=2;
        }
    }

    // rep(i, 30){
    //     rep(j, n){
    //         cout<<x[i][j]<<" ";
    //     }
    //     codl();
    // }

    vector<vector<ll>> s(30, vector<ll>(n+1, 0));
    vector<ll> ans(30, 0);
    rep(i, 30){
        ll c0=0, c1=0, sum=0;
        rep(j, n){
            s[i][j+1]=s[i][j]^x[i][j];
            sum+=x[i][j];
        }
        rep(j, n+1){
            if(s[i][j]==0)c0++;
            else c1++;
        }
        ans[i] = c0*c1-sum;
    }
    ll now=1, cnt=0;
    rep(i, 30){
        cnt+=now*ans[i];
        now*=2;
    }
    cout<<cnt<<endl;
}