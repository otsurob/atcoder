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
    ll w, b;
    cin>>w>>b;
    ll n=w+b;
    ll x=n/12, y=n%12; 
    w-=x*7;
    b-=x*5;
    ll d=w-b;
    ll wc, bc;
    string s="wbwbwwbwbwbw";
    if(y==0){
        if(w==b) couty()
        else coutn()
        return 0;
    }
    rep(i, 12){
        wc=0;
        bc=0;
        rep(j, y){
            if(s[(j+i)%12]=='w') wc++;
            else bc++;
        }
        if(w==wc and b==bc){
            couty()
            return 0;
        }
    }
    coutn()
    // if(w<0 or b<0 or d<-1) coutn()
    // else if(y==0){
    //     if(d==2) couty()
    //     else coutn()
    // }
    // else{
    //     if(d==0){
    //         if(y%2==0) couty()
    //         else coutn()
    //     }
    //     else if(d==1){
    //         if(y%2==1) couty()
    //         else coutn()
    //     }
    //     else if(d==2){
    //         if(y%2==0) couty()
    //         else coutn()
    //     }
    //     else if(d==3){
    //         if(y==7 or y==9 or y==11) couty()
    //         else coutn()
    //     }
    //     else if(d==-1){
    //         if(y==1 or y==3 or y==5) couty()
    //         else coutn()
    //     }
    //     else{
    //         coutn()
    //     }
    // }
    
}