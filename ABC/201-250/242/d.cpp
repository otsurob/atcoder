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

string s;

vector<char> abc={'A', 'B', 'C'};

ll func(ll t, ll k){
    if(t==0){
        return s[k]-'A';
    }
    if(k==0){
        ll sta=s[0]-'A';
        return  (sta+(t%3))%3;
    }
    if(k%2==0){
        return (func(t-1, k/2)+1)%3;
    }else{
        return (func(t-1, k/2)+2)%3;
    }
}

int main(){
    cin>>s;
    ll q;
    cin>>q;
    while(q--){
        ll t, k;
        cin>>t>>k;
        k--;
        cout<<abc[func(t, k)]<<endl;
    }
}