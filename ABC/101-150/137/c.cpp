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

// map<string, ll> mp;


int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    rep(i, n){
        cin>>s[i];
        sort(s[i].begin(), s[i].end());
    }
    sort(s.begin(), s.end());
    ll sum=0, tmp=1;
    rep2(1, i, n){
        if(s[i]==s[i-1]) tmp++;
        else if(tmp!=1){
            sum+=(tmp*(tmp-1))/2;
            tmp=1;
        }
    }
    if (tmp!=1) sum+=(tmp*(tmp-1))/2;
    cout<<sum<<endl;
    // rep(i, n) cout<<s[i]<<endl;
    // set<string> st;
    // rep(i, n) st.insert(s[i]);
    // cout<<n-st.size()<<endl;
}