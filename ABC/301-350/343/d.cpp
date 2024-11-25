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
    ll n, t;
    cin>>n>>t;
    vector<ll> a(t), b(t);
    rep(i, t) cin>>a[i]>>b[i];
    vector<ll> sc(n, 0);
    // vector<ll> cnt(1000000000, 0);
    map<ll, ll> mp;
    // cnt[0]=n;
    ll cnt=1;
    mp[0]=n;
    // set<ll> st;
    // st.insert(0);
    rep(i, t){
        ll tmp=sc[a[i]-1];
        // cnt[sc[a[i]-1]]--;
        ll m=mp[tmp];
        mp[tmp]=m-1;
        if(m==1) cnt--;
        // cout<<cnt[sc[a[i]-1]]<<'w'<<endl;
        // if(cnt[sc[a[i]-1]]==0) st.erase(cnt[sc[a[i]-1]]);
        sc[a[i]-1]+=b[i];
        tmp+=b[i];
        // st.insert(sc[a[i]-1]);
        // cnt[sc[a[i]-1]]++;
        if(mp.count(tmp)==0 or mp[tmp]==0){
            mp[tmp]=1;
            cnt++;
        }
        else{
            ll k=mp[tmp];
            mp[tmp]=k+1;
        }
        // cout<<st.size()<<endl;
        cout<<cnt<<endl;
    }
}