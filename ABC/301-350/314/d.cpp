#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    int n, q;
    string s;
    cin>>n>>s>>q;
    vector<int> t(q), x(q);
    vector<char> c(q);
    rep(i, q) {
        cin>>t[i]>>x[i]>>c[i];
        x[i]--;
    }
    int b=q, fl=0;
    for(int i=q-1; i>=0; i--){
        if(t[i]!=1){
            b=i;
            fl=t[i];
            break;
        }
    }
    rep(i, b){
        if(t[i]==1) s[x[i]]=c[i];
    }
    if(fl==2){
        rep(i, n){
            if(isupper(s[i])) s[i]+=32;
        }
    }else if (fl==3){
        rep(i, n){
            if(islower(s[i])) s[i]-=32;
        }
    }
    rep2(b, i, q){
        if(t[i]==1) s[x[i]]=c[i];
    }
    cout<<s<<endl;
}