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
#define pll pair<ll, ll>
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

//nex[i][c] <- 文字列sのi文字目以降で、文字cが最初に出現する最小の添字

vector<vector<ll>> calcNext(string ss){
    ll nn=ss.size();
    vector<vector<ll>> nex(nn+1, vector<ll>(26, -1));
    rrep(i, nn){
        nex[i]=nex[i+1];
        nex[i][ss[i]-'a']=i;
    }

    return nex;
}
