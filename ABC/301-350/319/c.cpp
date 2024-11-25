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
    vector<ll> c(9);
    cinv(c, 9);
    // rep(i, 9) cout<<c[i];
    // cout<<endl;
    vector<ll> o={0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<vector<ll>> a(8);
    ll sum=0, cnt=0;
    do{
        rep(i, 8) a[i]={};
        rep(i, 9){
            a[(o[i]%3)+3].push_back(c[o[i]]);
            a[o[i]/3].push_back(c[o[i]]);
            if(o[i]==2 or o[i]==4 or o[i]==6) a[6].push_back(c[o[i]]);
            if(o[i]==0 or o[i]==4 or o[i]==8) a[7].push_back(c[o[i]]);
        }
        rep(i, 8){
            if(a[i][0]==a[i][1]){
                cnt++;
                break;
            }
            // else{
            //     rep(j, 3) cout<<a[i][j]<<" ";
            //     cout<<"//";
            // }
        }
        sum++;
    }while(next_permutation(o.begin(), o.end()));
    double ans=(ld) (sum-cnt)/sum;
    // cout<<cnt<<" "<<sum<<endl;
    cout<<fixed<<setprecision(15)<<ans<<endl;
}