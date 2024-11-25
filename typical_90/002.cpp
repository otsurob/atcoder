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
    ll n;
    cin>>n;
    ll l=0, r=0;
    vector<string> ans;
    string s;
    for(ll i=0; i<(1<<n); i++){
        l=0;
        r=0; 
        ll flag=0;
        s="";
        rep(j, n){
            ll wari=1<<j;
            if((i/wari)%2==1){
                l++;
                s.push_back('(');
            }else{
                r++;
                s.push_back(')');
            }
            // cout<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
            if(l<r){
                flag=1;
                break;
            }
        }
        if(flag==0 and l==r) ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    rep(i, ans.size()) cout<<ans[i]<<endl;
}