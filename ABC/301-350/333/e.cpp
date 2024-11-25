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
    cin>>n;
    vector<ll> t(n), x(n);
    rep(i, n){
        cin>>t[i]>>x[i];
        x[i]--;
    }
    vector<ll> cnt(n, 0), gt(n, 0);
    rrep(i, n){
        if(t[i]==2){
            cnt[x[i]]++;
            gt[i]=-1;
        }
        else{
            if(cnt[x[i]]>0){
                cnt[x[i]]--;
                gt[i]=1;
            }
        }
    }
    rep(i, n){
        if(cnt[i]>0){
            cout<<-1<<endl;
            return 0;
        }
    }
    ll k=0, mx=-1;
    vector<ll> ans;
    rep(i, n){
        k+=gt[i];
        mx=max(mx, k);
        if(t[i]==1)ans.push_back(gt[i]);
    }
    cout<<mx<<endl;
    rep(i, ans.size())cout<<ans[i]<<" ";
    cout<<endl;
}