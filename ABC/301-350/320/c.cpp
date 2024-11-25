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
    ll m;
    cin>>m;
    vector<string> s(3);
    cin>>s[0]>>s[1]>>s[2];
    s[0]+=s[0]+s[0];
    s[1]+=s[1]+s[1];
    s[2]+=s[2]+s[2];
    ll ans=1000;
    vector<int> p={0, 1, 2};
    ll mt;
    rep(i, 10){
        mt=1000;
        do{
            ll flag=0;
            ll time=1000;
            rep(j, m*3){
                // cout<<flag<<endl;
                if(s[p[flag]][j]-'0'==i) flag++;
                if(flag==3){
                    time=j;
                    break;
                }
            }
            mt=min(mt, time);
        }while(next_permutation(p.begin(), p.end()));
        // cout<<mt<<endl;
        ans=min(ans, mt);
    }
    if(ans==1000) cout<<-1<<endl;
    else cout<<ans<<endl;
}