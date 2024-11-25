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

// ll m;


// ll saiki(ll n){
//     if(n==1) return 0;
//     if(n%2==0) return n+2*saiki(n/2);
//     else return n+saiki(n/2)+saiki((n/2)+1);
// }


int main(){
    ll m;
    cin>>m;
    ll n=1;
    ll count=0;
    // cout<<saiki(m)<<endl;;
    while(m>=n){
        n*=2;
        count++;
    }
    n/=2;count--;
    ll d = m-n;
    ll score=n*count;
    // cout<<n<<count<<endl;
    score+=d*count+2*d;
    cout<<score<<endl;
}