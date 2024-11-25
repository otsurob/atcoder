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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    string s;
    cin>>s;
    ll ai, bi;
    char a, b;
    rep(i, s.length()-1){
        if(s[i]!=s[i+1]){
            a=s[i];
            ai=i;
            b=s[i+1];
            bi=i+1;
            break;
        }
    }
    ll c=0, d=0;
    rep(i, s.length()){
        if(s[i]==a) c++;
        if(s[i]==b) d++;
    }
    // cout<<ai<<bi<<endl;
    if(c<d) cout<<ai+1<<endl;
    else cout<<bi+1<<endl;
}