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
    string s;
    cin>>s;
    int flag=0;
    rep(i, s.length()){
        if(s[i]=='A'){
            if(flag==0) continue;
            else{
                coutn();
                return 0;
            } 
        }
        else if(s[i]=='B'){
            if(flag==0) flag++;
            else if(flag==1) continue;
            else{
                coutn();
                return 0;
            }
        }
        else if(s[i]=='C'){
            if(flag==0) flag+=2;
            if(flag==1) flag++;
            else if(flag==2) continue;
            else{
                coutn();
                return 0;
            }
        }
        else{
            coutn();
            return 0;
        }
    }
    couty();
}