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
    ll q;
    cin>>q;
    map<char, vector<ll>> mp;
    rep(i, s.length()){
        if(mp.count(s[i])==0) mp[s[i]]={i};
        else mp[s[i]].push_back(i);
    }
    vector<pair<char, char>> p;
    rep2(97, i, 123){
        char k = i;
        p.push_back(pair<char, char>(k, k));
    }
    rep(i, q){
        char c, d;
        cin>>c>>d;
        // if(c==d) continue;
        // if(mp.count(c)==0) continue;
        rep(j, p.size()){
            if(p[j].second==c) p[j].second=d;
        }
        // if(mp.count(d)==0) mp[d]=mp[c];
        // else rep(j, mp[c].size()) mp[d].push_back(mp[c][j]);
        // else mp[d].insert(mp[d].end(), mp[c].begin(), mp[c].end());
        // mp[c]={};
    }
    rep2(97, i, 123){
        char e = i;
        if(mp.count(e)==0) continue;
        ll m = i-97;
        char t;
        t = p[m].second;
        rep(l, mp[e].size()) s[mp[e][l]]=t;
        // cout<<t<<endl;
        // rep(j, 26){
        //     // char x = j+97;
        //     if(p[m+j].first==e) t = p[m].second;
        //     cout<<t<<endl;
        //     rep(l, mp[t].size()) s[mp[t][l]]=t;
        // }
    }
    cout<<s<<endl;
}