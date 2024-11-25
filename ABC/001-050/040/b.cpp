#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t, mn=100000;
    cin>>n;
    int x = sqrt(n);
    // cout<<x<<endl;
    for (int i=x; i>0; i--){
        t = n-(i*i);
        // cout<<s<<endl;
        t=n-(i*i);
        mn=min(mn, (t/i)+(t-(i*(t/i))));
    }
    cout <<mn<<endl;
}
