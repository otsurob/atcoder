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
    ll n, m;
    cin>>n>>m;
    vector<ll> a(n);
    cinv(a, n);
    ll sum=0;
    rep(i, n)sum+=a[i];
    vector<ll> ans;
    sort(a.begin(), a.end());
    // rep(i, n)cout<<a[i]<<" ";
    // cout<<endl;
    ll sta=-1;
    rep(i, n-1){
        if(a[i+1]-a[i]>1){
            sta=i+1;
            break;
        }
    }
    if(sta==-1){
        cout<<0<<endl;
        return 0;
    }
    // coc(sta)
    ll s=0;
    rep(i, n){
        s+=a[(i+sta)%n];
        if((a[(i+sta+1)%n]-a[(i+sta)%n]>=0 and a[(i+sta+1)%n]-a[(i+sta)%n]<=1) or a[(i+sta)%n]-a[(i+sta+1)%n]==m-1){
            continue;
        }
        else{
            // coc2((sta+i)%n, s)
            ans.push_back(s);
            s=0;
        }
    }
    if(s!=0)ans.push_back(s);
    sort(ans.begin(), ans.end());
    // rep(i, ans.size())cout<<ans[i]<<" ";
    // cout<<endl;
    cout<<(ll)sum-ans[ans.size()-1]<<endl;
}