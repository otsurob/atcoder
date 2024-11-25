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
    ll r, c;
    cin>>r>>c;
    vector<string> b(r);
    cinv(b, r);
    vector<string> ans;
    ans=b;
    vector<vector<ll>> d={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    rep(i, r)rep(j, c){
        if(b[i][j]>'0' and b[i][j]<='9'){
            queue<vector<ll>> q;
            vector<vector<bool>> seen(r, vector<bool>(c, false));
            q.push({i, j, b[i][j]-'0'});
            seen[i][j]=true;
            while(!q.empty()){
                vector<ll> x=q.front();
                q.pop();
                ans[x[0]][x[1]]='.';
                if(x[2]==0) continue;
                rep(k, 4){
                    if(x[0]+d[k][0]>=0 and x[0]+d[k][0]<r and x[1]+d[k][1]>=0 and x[1]+d[k][1]<c and !seen[x[0]+d[k][0]][x[1]+d[k][1]]){
                        q.push({x[0]+d[k][0], x[1]+d[k][1], x[2]-1});
                        seen[x[0]+d[k][0]][x[1]+d[k][1]]=true;
                    }
                }
            }
        }
    }
    rep(i, r) cout<<ans[i]<<endl;
}