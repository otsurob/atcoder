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
    vector<vector<int>> a(9, vector<int>(9));
    rep(i, 9)rep(j, 9) cin>>a[i][j];
    rep(i, 9){
        vector<int> ck1(10, 0);
        vector<int> ck2(10, 0);
        rep(j, 9){
            ck1[a[i][j]]++;
            ck2[a[j][i]]++;
        }
        rep2(1, k, 10){
            if(ck1[k]!=1 or ck2[k]!=1){
                coutn();
                return 0;
            }
        }
    }
    // wow()
    for(int i=0; i<9; i+=3)for(int j=0; j<9; j+=3){
        vector<int> ck(10, 0);
        rep(n, 3)rep(m, 3){
            ck[a[n+i][m+j]]++;
        }
        rep2(1, k, 10) if(ck[k]!=1){
            coutn();
            return 0;
        }
    }
    couty();
}