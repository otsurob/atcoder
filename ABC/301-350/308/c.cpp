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

ll inf=9999999999;

void merge1(vector<vector<ll>> &a, ll l, ll m, ll r){
    ll n1=m-l, n2=r-m;
    vector<vector<ll>> lv(n1+1), rv(n2+1);
    rep(i, n1) lv[i]=a[l+i];
    rep(i, n2) rv[i]=a[m+i];
    lv[n1]={1, -2, inf};
    rv[n2]={1, -2, inf};

    ll lc=0, rc=0;
    rep2(l, i, r){
        // cout<<lv[lc][2]<<" "<<rv[rc][2]<<endl;
        if((lv[lc][0]*(rv[rc][0]+rv[rc][1]))==(rv[rc][0]*(lv[lc][0]+lv[lc][1]))){
            if(lv[lc][2]>rv[rc][2]){
                a[i]=lv[lc];
                lc++;
            }else{
                a[i]=rv[rc];
                rc++;
            }
        }
        else if(lv[lc][0]*(rv[rc][0]+rv[rc][1])<rv[rc][0]*(lv[lc][0]+lv[lc][1])){
            a[i]=lv[lc];
            lc++;
        }else{
            a[i]=rv[rc];
            rc++;
        }

    }
}


void merge_sort(vector<vector<ll>> &a, ll l, ll r){
    //l+1=r すなわち要素数が1のときは何もしない
    if(l+1<r){
        ll mid=(l+r)/2;

        merge_sort(a, l, mid);
        merge_sort(a, mid, r);

        merge1(a, l, mid, r);
    }
}



int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> x(n);
    rep(i, n){
        ll a, b;
        cin>>a>>b;
        x[i]={a, b, i};
    }
    merge_sort(x, 0, n);
    rrep(i, n) cout<<x[i][2]+1<<" ";
    cout<<endl;


}