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
    vector<ll> a(k);
    cinv(a, k);
    vector<ll> stock(n, 2);
    rep(i, k) stock[a[i]-1]--;
    vector<ll> s;
    rep(i, n) rep(j, stock[i]) s.push_back(i);
    
    // rep(i, s.size()) cout<<s[i]<<" ";
    // cout<<endl;

    if(s.size()%2==0){
        ll ans=0;
        rep(i, s.size()/2) ans+=(s[(2*i)+1]-s[(2*i)]);
        cout<<ans<<endl;
    }else{
        ll z = (s.size()-1)/2;
        vector<ll> sm1(z);
        vector<ll> sm2(z);
        sm1[0]=s[1]-s[0];
        sm2[0]=s[2]-s[1];
        rep2(1, i, z){
            sm1[i]=sm1[i-1]+(s[(i*2)+1]-s[i*2]);
            sm2[i]=sm2[i-1]+(s[(i*2)+2]-s[(i*2)+1]);
        }
        ll sum;
        ll mn=numeric_limits<ll>::max();
        rep(i, s.size()){
            sum=0;
            if(i%2==0){
                sum+=sm1[(i/2)-1]+sm2[z-1]-sm2[(i/2)-1];
            }
            else{
                sum+=sm1[(i-1)/2]+sm2[z-1]-sm2[(i-1)/2]+(s[i+1]-s[i-1]);
            }
            mn=min(mn, sum);
        }
        cout<<mn<<endl;
    }
}