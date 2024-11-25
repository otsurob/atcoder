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
void chmin(int &a, int b) { a = min(a, b); }
void chmax(int &a, int b) { a = max(a, b); }
int main(){
    ll n, d;
    cin>>n>>d;
    vector<ll> x(n), y(n);
    rep(i, n){
        cin>>x[i]>>y[i];
        x[i]+=1000000, y[i]+=1000000;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<ll> dx(2000001), dy(2000001);
    ll sx=0, sy=0;
    rep(i, n){
        sx+=x[i];
        sy+=y[i];
    }
    dx[0]=sx, dy[0]=sy;
    ll cx=0, cy=0;
    rep2(1, i, 2000001){
        while(cx<n and x[cx]==i-1){
            cx++;
        }
        sx=sx+cx-(n-cx);
        dx[i]=sx;
    }
    rep2(1, i, 2000001){
        while(cy<n and y[cy]==i-1){
            cy++;
        }
        sy=sy+cy-(n-cy);
        dy[i]=sy;
    }
    sort(dx.begin(), dx.end());
    sort(dy.begin(), dy.end());
    ll l=0, r=0;
    ll ans=0;
    rep(i, 2000001){
        while(l!=n and dx[l]+dy[i]<=d){
            l++;
        }
        if(l==0)break;
        l--;
        ans+=l+1;
    }
    cout<<ans<<endl;
}
