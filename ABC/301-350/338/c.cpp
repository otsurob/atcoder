#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> q(n), a(n), b(n);
    for (int i=0; i<n; i++) cin>>q[i];  
    for (int i=0; i<n; i++) cin>>a[i];  
    for (int i=0; i<n; i++) cin>>b[i];
    long long mn=100000000;
    for (int i=0; i<n; i++){
        if(a[i]==0) continue;
        if(q[i]/a[i]<mn){
            mn=q[i]/a[i];
        }
    }

    long long mx=mn;
    long long mn2;
    // cout<<mx<<endl;
    for (int i=0; i<=mn; i++){
        mn2=1000000000;
        for (int j=0; j<n; j++){
            if (b[j]==0) continue;
            // cout << (q[j]-(a[j]*(mn-i)))/b[j] << endl;
            if(((q[j]-(a[j]*(mn-i)))/b[j])<mn2){
                mn2=(q[j]-(a[j]*(mn-i)))/b[j];
            }
        }
        // cout << mn << " " << i << " " << mn2 << endl;
        if(mx<mn-i+mn2){
            mx=mn-i+mn2;
        }
    }
    if(mn==0){
        mn=1000000000;
        for (int i=0; i<n; i++){
            if(b[i]==0) continue;
            if(q[i]/b[i]<mn){
                mn=q[i]/b[i];
            }
        }
        mx=mn;
    }
    cout<<mx<<endl;
}