#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll a, b, c;
    cin>>a>>b>>c;
    ll tc=c;
    ll cnt=0;
    vector<ll> pc(60), px(60), py(60);
    rep(i, 60){
        if(c%2==1){
            cnt++;
            pc[i]=1;
        }
        else pc[i]=0;
        c/=2;
    }
    ll d=abs(a-b);
    ll dd = cnt-d;
    if(dd<0 or dd%2!=0){
        cout<<-1<<endl;
        return 0;
    }
    rep(i, 60){
        if(pc[i]==0)continue;
        if(a>=b){
            px[i]=1, py[i]=0;
            a--;
        }
        else{
            px[i]=0, py[i]=1;
            b--;
        }
    }
    rep(i, 60){
        if(pc[i]==1)continue;
        else{
            if(a!=0){
                px[i]=1, py[i]=1;
                a--, b--;
            }
            else {
                px[i]=0, py[i]=0;
            }
        }
    }
    if(a!=0 or b!=0){
        cout<<-1<<endl;
        return 0;
    }
    ll x=0, y=0;
    ll z=1;
    rep(i, 60){
        if(px[i]==1)x+=z;
        if(py[i]==1)y+=z;
        z*=2;
    }
    cout<<x<<" "<<y<<endl;
}