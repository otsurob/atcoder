#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, mn, mx=0, mx2=0;
    cin>>n;
    vector<int> f(n);
    vector<long long> s(n);
    for(int i=0; i<n; i++){
        cin>>f[i]>>s[i];
        if(mx<s[i]){
            mx=s[i];
            mn=i;
        }
    }
    for(int i=0; i<n; i++){
        if(mn==i) continue;
        if(f[i]==f[mn]) s[i]/=2;
        if(s[i]>mx2) mx2=s[i];
    }
    cout << mx+mx2 << endl;
}