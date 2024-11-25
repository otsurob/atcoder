#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> a(5);
    cin>>a[0];
    for (int i=1; i<5; i++){
        cin>>a[i];
        if(a[i-1]<a[i]) a[i]=a[i-1];
    }
    long long ans=0;
    ans=(n/a[4])+4;
    if(n%a[4]!=0) ans++;
    cout<<ans<<endl;
}