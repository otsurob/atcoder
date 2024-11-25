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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> v(26, 0);
    string t;
    v[s[0]-'a']++;
    ll count=1;
    t=s[0];
    rep2(1, i, n){
        if(s[i]==s[i-1]) count++;
        else{
            count=1;
        }
        v[s[i]-'a']=max(v[s[i]-'a'], count);
    }
    ll ans=0;
    rep(i, 26) ans+=v[i];
    cout<<ans<<endl;

}