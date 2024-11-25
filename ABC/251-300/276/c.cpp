#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, m, y;
    cin>>n;
    vector<int> a(n), b(1);
    for (int i=0; i<n; i++) cin>>a[i];
    if(a.size()==2){
        cout<<a[1]<<" "<<a[0]<<endl;
        return 0;
    }
    b[0]=a[n-1];
    for (int i=1; i<n; i++){
        b.push_back(a[n-1-i]);
        if(a[n-1-i]>b[i-1]){
            x=a[n-1-i];
            m=i;
            break;
        }
    }
    sort(b.begin(), b.end());
    for (int i=0; i<b.size(); i++){
        if(b[i]==x){
            y=b.size()-i;
            break;
        }
    }
    sort(b.rbegin(), b.rend());
    // for (int i=0; i<b.size(); i++) cout<<b[i]<<" ";
    // cout<<endl;
    for(int i=0; i<n-b.size(); i++) cout<<a[i]<<" ";
    // cout<<y<<"y"<<endl;
    cout<<b[y]<<" ";
    for (int i=0; i<b.size(); i++){
        if(i==y) continue;
        cout<<b[i]<<" ";
    }
    cout<<endl;
}