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
    ll n;
    ll inf=9999999999999;
    cin>>n;
    // deque<ll> a(n);
    vector<ll> a(n);
    cinv(a, n);
    sort(a.begin(), a.end());
    deque<ll> t;
    t.push_back(a[0]);
    rep2(1, i, n){
        if(a[i]==a[i-1]) t.push_back(inf);
        else t.push_back(a[i]);
    }
    sort(t.begin(), t.end());
    ll nx=0;
    while(!t.empty()){
        nx++;
        if(nx==t.front()){
            t.pop_front();
            // nx++;
        }else{
            if(t.size()<2){
                nx--;
                cout << nx << endl;
                return 0;
                //break;
            }
            // rep(i, 2){
            //     if(t.front()<nx) t.pop_front();
            //     if(t.size()>=1) t.pop_back();
            //     else{
            //         cout<<nx-1<<endl;
            //         return 0;
            //     }
            // }
            // nx++;
            t.pop_back();
            t.pop_back();
        }
    }
    cout<<nx<<endl;

}