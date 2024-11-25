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
    ll n, m;
    cin>>n>>m;
    vector<ll> a(m);
    cinv(a, m);
    vector<ll> sm(n, 0);
    vector<string> s(n);
    ll ms=-1;
    vector<vector<ll>> pro(n);
    rep(i, n){
        cin>>s[i];
        rep(j, m){
            if(s[i][j]=='o'){
                sm[i]+=a[j];
            }else{
                pro[i].push_back(a[j]);
            }
        }
        sm[i]+=i;
        // cout<<sm[i]<<endl;
        ms=max(ms, sm[i]);
    }
    // cout<<ms<<endl;
    rep(i, n){
        sort(pro[i].rbegin(), pro[i].rend());
        ll d = ms-sm[i];
        ll count=0;
        while(ms>sm[i]){
            sm[i]+=pro[i][count];
            count++;
        }
        cout<<count<<endl;
    }
}