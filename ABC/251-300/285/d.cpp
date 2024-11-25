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
    vector<string> s(n), t(n);
    set<string> sts, stt;
    map<string, string> mp;
    rep(i, n){
        cin>>s[i]>>t[i];
        sts.insert(s[i]);
        stt.insert(t[i]);
        mp[t[i]]=s[i];
    }
    ll count=0;
    queue<string> q;
    rep(i, n){
        if(sts.find(t[i])==sts.end()){
            q.push(t[i]);
        }
    }
    while(!q.empty()){
        string a = q.front();
        q.pop();
        // cout<<a<<endl;
        count++;
        if(stt.find(mp[a])!=stt.end()){
            q.push(mp[a]);
        }
    }
    if(count==n){couty()}
    else coutn();
}