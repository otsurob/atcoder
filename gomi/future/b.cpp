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
    string s, t;
    cin>>s>>t;
    vector<string> sdir, tdir;
    string ts, tt;
    rep2(1, i, s.length()){
        if(s[i]=='/'){
            sdir.push_back(ts);
            ts="";
        }
        else ts.push_back(s[i]);
    }
    rep2(1, i, t.length()){
        if(t[i]=='/'){
            tdir.push_back(tt);
            tt="";
        }
        else tt.push_back(t[i]);
    }
    int len = min(sdir.size(), sdir.size());
    int num=-1;
    rep(i, len){
        if(sdir[i]!=tdir[i]){
            num=i;
            break;
        }        
    }
    int ans=0;
    if(num==-1){
        ans=max(sdir.size(), tdir.size())-len;
    }
    else{
        ans=sdir.size()-num+tdir.size()-num;
    }
    cout<<ans<<endl;
}