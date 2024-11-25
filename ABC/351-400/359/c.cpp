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
    ll sx, sy, tx, ty;
    cin>>sx>>sy>>tx>>ty;
    ll ans=abs(ty-sy);
    if(sx==tx){
        ans=abs(ty-sy);
        cout<<ans<<endl;
        return 0;
    }
    else if(abs(sx-tx)==1){
        if(ty==sy){
            if(ty%2==0){
                if(max(sx, tx)%2==0)ans++;
            }else{
                if(max(sx, tx)%2==1)ans++;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    else if(sx>tx){
        if(sx%2==0 and sy%2==1)sx--;
        if(sx%2==1 and sy%2==0)sx--;
        if(tx%2==0 and ty%2==0)tx++;
        if(tx%2==1 and ty%2==1)tx++;
    }
    else {
        if(tx%2==0 and ty%2==1)tx--;
        if(tx%2==1 and ty%2==0)tx--;
        if(sx%2==0 and sy%2==0)sx++;
        if(sx%2==1 and sy%2==1)sx++;
    }

    if(abs(tx-sx)>abs(ty-sy)){
        ans+=(abs(tx-sx)-abs(ty-sy)+1)/2;
    }
    cout<<ans<<endl;
}