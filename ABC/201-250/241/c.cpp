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
    ll n;
    cin>>n;
    vector<string> s(n);
    rep(i, n) cin>>s[i];
    rep(i, n)rep(j, n){
        ll c1=0, c2=0, c3=0, c4=0;
        rep(k, 6){
            if(j+k>=n){
                c1=6;
                break;
            }
            if(s[i][j+k]=='.') c1++;
        }
        rep(k, 6){
            if(i+k>=n){
                c2=6;
                break;
            }
            if(s[i+k][j]=='.') c2++;
        }
        rep(k, 6){
            if(i+k>=n or j+k>=n){
                c3=6;
                break;
            }
            if(s[i+k][j+k]=='.') c3++;
        }
        rep(k, 6){
            if(i+k>=n or j-k<0){
                c4=6;
                break;
            }
            if(s[i+k][j-k]=='.') c4++;
        }
        if(c1<3 or c2<3 or c3<3 or c4<3){
            couty();
            return 0;
        }
    }
    coutn();
}