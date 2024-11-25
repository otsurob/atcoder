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
    string s;
    ll n;
    cin>>s>>n;
    ll m=s.length();
    ll flag=0, f2=0;
    ll w=1;
    ll tmp=n;
    string x="";
    rep(i, m){
        ll k=n%2;
        char y = k+'0';
        x = y+x;
        // coc(x)
        n/=2;
    }
    // cout<<x<<endl;
    ll ans=0, z, cnt=0;
    while(tmp>0){
        cnt++;
        tmp/=2;
    }
    // coc(cnt)
    if(cnt>m) flag=1;
    rep(i, m-1) w*=2;
    // coc(w)
    ll sub=0;
    rep(i, m){
        if(flag==0){
            if(s[i]=='1' and x[i]=='0'){
                if(sub==ans){
                    cout<<-1<<endl;
                    return 0;
                }
                else{
                    ans=sub;
                    flag=1;
                    z=1;
                }
            }
            else if(s[i]=='0' and x[i]=='1'){
                flag=1;
                z=0;
            }
            else if(f2==1 and s[i]=='?' and x[i]=='0'){
                sub+=w*1;
                z=0;
            }
            else if(s[i]=='?' and x[i]=='1'){
                sub=ans;
                z=x[i]-'0';
                sub-=w*z;
                f2=1;
            }
            else{
                z=x[i]-'0';
            }
        }else{
            if(s[i]=='?'){
                z=1;
            }
            else{
                z=s[i]-'0';
            }
        }
        ans+=w*z;
        sub+=w*z;
        w/=2;
        // coc2(sub, ans)
        // coc(ans)
    }
    cout<<ans<<endl;
}