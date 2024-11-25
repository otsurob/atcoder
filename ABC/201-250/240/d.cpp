#include <bits/stdc++.h>
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    cinv(a, n)
    vector<int> rv(0), nv(0);
    nv.push_back(a[0]);
    rv.push_back(1);
    int ans=1, count=1;
    cout<<ans<<" ";
    rep2(1,i, n){
        // cout<<a[i]<<count<<ans<<nv.back()<<rv.back()<<endl;;
        ans++;
        if(a[i]==nv.back()) count++;
        else count=1;
        if(a[i]==count){
            ans -= a[i];
            rep(j, count-1){
                nv.pop_back();
                rv.pop_back();
            }
            count=rv.back();
            // cout<<count<<nv.back();
        }else{
            nv.push_back(a[i]);
            rv.push_back(count);
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}