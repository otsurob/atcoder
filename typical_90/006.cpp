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

int main(){
    ll n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<vector<ll>> nex(n+1, vector<ll>(26, -1));
    rrep(i, n){
        rep(j, 26){
            char c=j+'a';
            // cout<<c<<endl;
            if(s[i]==c) nex[i][j]=i;
            else nex[i][j]=nex[i+1][j];
        }
    }
    // wow();

    ll now=0;
    vector<char> ans;
    rep(i, k){
        rep(j, 26){
            if(nex[now][j]!=-1 and n-nex[now][j]>=k-i){
                // cout<<nex[now][j]<<endl;
                ans.push_back(j+'a');
                now=nex[now][j]+1;
                break;
            }
        }
        // cout<<now<<endl;
    }
    rep(i, k) cout<<ans[i];
    cout<<endl;
}