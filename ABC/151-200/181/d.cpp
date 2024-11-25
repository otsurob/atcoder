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
    string s;
    cin>>s;
    vector<int> ns(10, 0);
    if(s.length()==1){
        if((int(s[0])-'0')%8==0) {couty();}
        else coutn();
        return 0;
    }else if(s.length()==2){
        if((((int(s[0])-'0')*10+int(s[1])-'0')%8==0)or(((int(s[1])-'0')*10+int(s[0])-'0')%8==0)){couty();}
        else coutn();
        return 0;
    }
    // cout<<int(s[0])<<endl;
    rep(i, s.length()) ns[int(s[i])-'0']++;
    if(s.length()<3) ns[0]+=3-s.length();
    int n=0;
    // rep(k, 10) cout<<ns[k]<<endl;
    rep2(1, i, 126){
        n+=8;
        int n1=n%10, n2=(n/10)%10, n3=(n/100)%10;
        vector<int> ns2(10, 0);
        ns2[n1]++; ns2[n2]++; ns2[n3]++;
        // rep(k, 10) cout<<ns2[k];
        // cout<<endl;
        bool flag = true;
        rep(j, 10){
            if(ns[j]<ns2[j]) flag=false;
        }
        if(flag){
            couty();
            return 0;
        }
    }
    coutn();
}