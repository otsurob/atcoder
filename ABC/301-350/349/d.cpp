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

ll cnt=0;
vector<pll> ans;
ll sta=powl(2, 60);

void calc(ll l, ll r, ll x){
    if(r==l) return;
    if(r-l==1){
        // coc2(l, r)
        ans.push_back(pll(l, r));
        cnt++;
        return;
    }
    ll d=r-l;
    while(true){
        if(x==0){
            // cout<<"asd"<<endl;
            // coc2(l, r)
            ans.push_back(pll(l, l+1));
            ans.push_back(pll(l+1, l+2));
            cnt+=2;
            return;
        }
        if(d/x==0){
            x/=2;
            continue;
        }
        ll ln, rn;
        if(l%x==0) ln=l;
        else{
            ln=((l/x)+1)*x;
            // coc2(ln, x)
        }
        // coc2(ln, x)
        if(ln+x<=r){
            cnt++;
            // wow()
            // coc2(ln, x)
            ans.push_back(pll(ln, ln+x));
            ll y=ln+x;
            calc(l, ln, sta);
            calc(y, r, sta);
            return;
        }else{
            x/=2;
            continue;
        }
    }
}


int main(){
    ll l, r;
    cin>>l>>r;
    calc(l, r, sta);
    cout<<cnt<<endl;
    sort(ans.begin(), ans.end());
    rep(i, ans.size()) cout<<ans[i].fst<<" "<<ans[i].snd<<endl;
}