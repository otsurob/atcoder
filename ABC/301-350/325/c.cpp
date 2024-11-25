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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main(){
    ll h, w;
    cin>>h>>w;
    vector<string> s(h);
    cinv(s, h);
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    vector<ll> dx={0, 0, 1, 1, -1, -1, 1, -1};
    vector<ll> dy={1, -1, 1, -1, 1, -1, 0, 0};
    queue<pair<ll, ll>> q;
    ll count=0;
    rep(i, h)rep(j, w){
        if(seen[i][j]) continue;
        seen[i][j]=true;
        if(s[i][j]=='#'){
            q.push(pll(i, j));
            while(!q.empty()){
                ll a=q.front().first;
                ll b=q.front().second;
                q.pop();
                rep(k, 8){
                    ll na=a+dx[k];
                    ll nb=b+dy[k];
                    if(na<0 or na>=h or nb<0 or nb>=w) continue;
                    if(seen[na][nb]) continue;
                    if(s[na][nb]=='#'){
                        q.push(pll(na, nb));
                        seen[na][nb]=true;
                    }
                }
            }
            count++;
        }
    }
    cout<<count<<endl;
}