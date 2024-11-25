#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n=0, ans=0, count=0;
    cin >> n;
    n--;
    while(n!=0){
        ans += (n%5)*powl(10, count);
        count++;
        n = n/5;
        // cout << ans << endl;
    }
    // cout << ans << endl;
    cout << 2*ans << endl;
}