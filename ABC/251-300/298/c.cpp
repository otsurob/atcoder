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
#define coc(a) cout<<a<<endl;
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
    ll n, m, i, j;
    cin>>n;
    ll q;
    cin>>q;
    vector<vector<ll>> box(200009, vector<ll>()), card(200009, vector<ll>());
    while(q--){
        cin>>m>>i;
        if(m==1){
            cin>>j;
            box[j].push_back(i);
            card[i].push_back(j);
        }else if(m==2){
            sort(box[i].begin(), box[i].end());
            rep(k, box[i].size()) cout<<box[i][k]<<" ";
            cout<<endl;
        }else{
            sort(card[i].begin(), card[i].end());
            // set<ll> st;
            // rep(k, card[i].size()) st.insert(card[i][k]);
            // for(auto x : st) cout<<x<<" ";
			card[i].erase(unique(card[i].begin(), card[i].end()), card[i].end());
            rep(k, card[i].size()) cout<<card[i][k]<<" ";
            cout<<endl;
        }
    }
}