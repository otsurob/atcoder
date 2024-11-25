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
    ll n;
    cin>>n;
    string t;
    cin>>t;
    ll lnt=t.length();
    vector<string> s(n);
    vector<ll> lns(n);
    vector<ll> ans;
    rep(i, n){
        cin>>s[i];
        lns[i]=s[i].length();
    }
    rep(i, n){
        ll count=0;
        ll num=0;
        if(abs(lnt-lns[i])>=2) continue;
        else if((lnt-lns[i])==1){
            rep(j, lns[i]){
                if(t[num]!=s[i][j]){
                    count++;
                    j--;
                }
                if(count>=2) break;
                num++;
            }
        }
        else if((lnt-lns[i])==-1){
            rep(j, lnt){
                if(t[j]!=s[i][num]){
                    count++;
                    j--;
                }
                if(count>=2) break;
                num++;
            }
        }
        else if(lnt==lns[i]){
            rep(j, lnt){
                if(t[j]!=s[i][j]) count++;
            }
        }
        if(count<2) ans.push_back(i+1);
    }
    cout<<ans.size()<<endl;
    rep(i, ans.size()) cout<<ans[i]<<" ";
    cout<<endl;
}