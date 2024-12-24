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
    vector<ll> a(5);
    // ll a, b, c, d, e;
    // cin>>a>>b>>c>>d>>e;
    cinv(a, 5);
    vector<char> t={'A', 'B', 'C', 'D', 'E'};
    vector<pair<ll, string>> s;
    rep2(1, i, 1<<5){
        ll sum=0;
        string name="";
        rep(j, 5){
            ll wari = 1<<j;
            if((i/wari)%2==1){
                sum+=a[j];
                name+=t[j];
            }
        }
        s.push_back(pair<ll, string>(-sum, name));
    }
    sort(s.begin(), s.end());
    rep(i, s.size()){
        cout<<s[i].snd<<endl;
    }
}