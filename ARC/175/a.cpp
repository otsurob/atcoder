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
    vector<ll> p(n);
    vector<ll> q(n);
    rep(i, n){
        cin>>p[i];
        p[i]--;
        q[p[i]]=i;
    }
    string s, tmp;
    cin>>s;
    tmp=s;
    ll ans=1, now, x, y;
    now=p[0];
    if(n==2){
        rep(i, n){
            if(s[i]=='?') ans*=2;
        }
        cout<<ans<<endl;
        return 0;
    }

    if(s[p[0]]=='?'){
        now=p[0];
        tmp[now]='L';
        x=(now-1+n)%n;
        y=(now-2+n)%n;
        rep(i, n-2){
            if(q[x]<q[y]){
                if(tmp[y]=='?') ans*=2;
            }else {
                if(tmp[x]=='?' and i<=0) ans*=2;
                if(tmp[y]=='R') ans=0;
                tmp[y]='L';
            }
            // coc3(x, y, ans)
            x=(x-1+n)%n;
            y=(y-1+n)%n;
        }
        ll ans2=1;
        tmp=s;
        now=p[0];
        tmp[now]='R';
        x=(now+1+n)%n;
        y=(now+2+n)%n;
        rep(i, n-2){
            if(q[x]<q[y]){
                if(tmp[y]=='?') ans2*=2;
            }else {
                if(tmp[x]=='?' and i<=1) ans2*=2;
                if(tmp[y]=='L') ans2=0;
                tmp[y]='R';
            }
            // coc3(x, y, ans2);
            x=(x+1+n)%n;
            y=(y+1+n)%n;
        }
        // coc2(ans, ans2)
        ans+=ans2;
    }else{
        if(s[p[0]]=='L'){
            rep(i, n-2){
                x=(now-1+n)%n;
                y=(now-2+n)%n;
                if(q[x]<q[y]){
                    if(s[x]=='?') ans*=2;
                }else {
                    if(s[x]=='?') ans*=2; 
                    if(s[y]=='R') ans=0;
                }
            }
        }else{
            rep(i, n-2){
                x=(now+1+n)%n;
                y=(now+2+n)%n;
                if(q[x]<q[y]){
                    if(s[x]=='?') ans*=2;
                }else {
                    if(s[x]=='?') ans*=2;
                    if(s[y]=='L') ans=0;
                }
            }
        }
    }
    cout<<(ll)(ans%998244353)<<endl;
}