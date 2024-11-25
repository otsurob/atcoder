#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    string s, t;
    cin>>s>>t;
    vector<int> sv(27, 0), tv(27, 0);
    int cs=0, ct=0;
    rep(i, s.length()){
        if(s[i]=='@') sv[26]++;
        else sv[int(s[i])-97]++;
        if(t[i]=='@') tv[26]++;
        else tv[int(t[i])-97]++;        
    }
    rep(i, 26){
        if(sv[i]!=tv[i]){
            if(i!=0 and i!=2 and i!=3 and i!=4 and i!=14 and i!=17 and i!=19){
                coutn();
                // cout<<"wow"<<endl;
                return 0;
            }
            else if(sv[i]>tv[i]) cs += sv[i]-tv[i];
            else ct += tv[i]-sv[i];
        }
    }
    // cout<<ct<<" "<<cs<<tv[26]<<sv[26]<<endl;
    if(tv[26]>=cs and sv[26]>=ct){
        couty();
    }else coutn();
}
