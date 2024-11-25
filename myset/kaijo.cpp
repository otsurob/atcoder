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
    ll k;
    cin>>k;
    ll mx=-1;
    for(ll i=2; (i*i)<=k; i++){
        ll cnt=0;   //iの倍数が何個含まれるかをカウント
        while(k%i==0){
            k/=i;
            cnt++;
        }
        ll x=0;   //iの倍数を小さいほうから順番に加算。cntがなくなるまで続行
        while(cnt>0){
            x+=i;
            ll tmp=x;
            while(tmp%i==0){
                tmp/=i;
                cnt--;
            }
        }
        mx=max(mx, x);
    }
    mx=max(mx, k);   //残ったkがめちゃでかい素数の可能性がある
    cout<<mx<<endl;
}