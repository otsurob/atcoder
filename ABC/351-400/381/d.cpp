#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<' ';
#define codl() cout<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
#define decout(a) cout<<fixed<<setprecision(15)<<a<<endl;
#define wow() cout<<"wow"<<endl;
#define coc(a) cout<<a<<endl;;
#define coc2(a, b) cout<<a<<" "<<b<<endl;
#define coc3(a, b, c) cout<<a<<" "<<b<<" "<<c<<endl;
#define coc4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define pll pair<ll, ll>
#define fst first
#define snd second
#define inf 999999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    cinv(a, n);
    ll l=1, r=1;
    set<ll> st;
    ll mx=0;
    while(l<n and r<n){
        if(a[l-1]!=a[l]){
            l++, r++;
            continue;
        }
        st.insert(a[l]);
        chmax(mx, st.size());
        if(l==r){
            r+=2;
            continue;
        }
        if(a[r-1]!=a[r]){
            st.clear();
            l=r-1, r--;
            continue;
        }
        if(st.find(a[r])!=st.end()){
            // coc2(a[l], st.size())
            st.erase(a[l]);
            l+=2;
            continue;
        }
        // coc4(l, r, a[r], st.size())
        st.insert(a[r]);
        r+=2;
        chmax(mx, st.size());
    }
    cout<<2*mx<<endl;
}