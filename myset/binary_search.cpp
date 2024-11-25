#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;
int search(int x){
    int l = 1, r = n;
    while(l<=r){
        int m = (l+r)/2;
        if(x<v.at(m)) r=m-1;
        if(x>v.at(m)) l=m+1;
        if(x==v.at(m)) return m;
    }
    return -1;
}

int main(){
    int a=0;
    cin >> n >> k;
    // cout << n << k << endl;
    for(int i=0; i<n; i++){
        cin >> a;
        v.push_back(a);
    }
    cout << v.at(2) << endl;
    int ans = search(k);
    cout << ans << endl;
}