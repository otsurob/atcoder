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
#define inf 999999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> ans;
    vector<ll> a(n), b(n);
    ll now=1;
    rep(i, n){
        a[i]=now;
        now+=10;
    }
    now=m;
    rrep(i, n){
        b[i]=now;
        now-=10;
    }
    ans.push_back(a);
    ll p;
    bool f=false;
    while(true){
        f=false;
        if(a[n-1]==m){
            rrep(i, n){
                if(a[i]!=b[i]){
                    p=i;
                    a[i]++;
                    f=true;
                    break;
                }
            }
            if(!f){
                cout<<ans.size()<<endl;
                rep(i, ans.size()){
                    rep(j, n)cout<<ans[i][j]<<" ";
                    codl()
                }
                return 0;
            }
            rep2(p+1, i, n){
                a[i]=a[i-1]+10;
            }
        }else{
            a[n-1]++;
        }
        ans.push_back(a);
    }
}