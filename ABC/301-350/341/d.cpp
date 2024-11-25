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

ull gcd(ull x, ull y){
    if(y==0) return x;
    else return gcd(y, x%y);
}


ull lcm(ull x, ull y){
    return x/gcd(x, y)*y;
}


int main(){
    ull n, m, k;
    cin>>n>>m>>k;
    ull l=0, r=1e19;
    ull g = lcm(n, m);
    // cout<<g<<endl;
    ull ans;
    while(l<=r){
        ull mid = (l+r)/2;
        ull num = (mid/n)+(mid/m)-2*(mid/g);
        // cout<<mid<<" "<<num<<endl;
        if(num>k) r=mid;
        else if(num<k) l=mid;
        else{
            ans = mid;
            break;
        }
    }
    // cout<<ans<<endl;
    while(true){
        if(ans%n==0 or ans%m==0){
            if(ans%n!=0 or ans%m!=0) break;
        }
        ans--;
    }
    cout<<ans<<endl;
}