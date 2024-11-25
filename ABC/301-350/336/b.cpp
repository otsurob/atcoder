#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=0, count=0;
    cin >> n;
    while (n%2==0){
        count++;
        n = n/2;
    }
    cout << count << endl;
}