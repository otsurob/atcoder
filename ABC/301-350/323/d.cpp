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
    vector<ll> s(n), c(n);
    vector<pll> p;
    rep(i, n){
        cin>>s[i]>>c[i];
        p.push_back(pll(s[i], c[i]));
    }
    sort(p.begin(), p.end());
    ll a=-1, b=-1, x, sum=0;
    queue<pll> q;
    rep(i, n){
        while(!q.empty()){
            if(q.front().fst>=p[i].fst) break;
            sum+=q.front().snd%2;
            a=2*q.front().fst;
            b=q.front().snd/2;
            q.pop();
            q.push(pll(a, b));
        }
        x=p[i].snd;
        if(p[i].fst==q.front().fst){
            x+=q.front().snd;
            q.pop();
        }
        if(x%2==1) sum++;
        a=2*p[i].fst;
        b=x/2;
        q.push(pll(a, b));
    }
    while(!q.empty()){
        b=q.front().snd;
        q.pop();
        while(b>0){
            sum+=b%2;
            b/=2;
        }
    }

    cout<<sum<<endl;
}