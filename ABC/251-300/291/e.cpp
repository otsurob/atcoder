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

//indegreeは入次数を管理する配列
vector<ll> topological(vector<vector<ll>> g, vector<ll> indegree){
    ll tn=g.size();
    vector<ll> sorted_vector, fail(tn, -1);
    queue<ll> q;
    rep(i, tn){
        if(indegree[i]==0)q.push(i);
    }
    if(q.size()!=1)return fail;
    while(!q.empty()){
        ll tv=q.front();
        q.pop();
        // coc(tv)
        // その頂点と隣接している頂点の入次数を減らし、0になればキューに追加
        rep(i, g[tv].size()) {
            int tu = g[tv][i];
            indegree[tu] -= 1;
            if (indegree[tu] == 0) q.push(tu);
        }
        sorted_vector.push_back(tv);
        if(q.size()>1)return fail;
    }
    return sorted_vector;
}


int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll> x(m), y(m);
    vector<vector<ll>> g(n);
    rep(i, m){
        cin>>x[i]>>y[i];
        x[i]--, y[i]--;
        g[x[i]].push_back(y[i]);
    }
    vector<ll> ind(n);
    rep(i, m){
        ind[y[i]]++;
    }
    vector<ll> ans=topological(g, ind), check(n, -1);
    if(ans==check)coutn()
    else{
        couty()
        vector<ll> ta(n);
        rep(i, n)ta[ans[i]]=i+1;
        rep(i, n)cout<<ta[i]<<" ";
        cout<<endl;
    }
}