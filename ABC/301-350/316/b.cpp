#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, n, b;
    cin >> n;
    vector<int> v;
    for (int i=0; i<n; i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    b=v[0];
    for (int i=0; i<n; i++){
        // cout << v[i] << " " << b << endl;
        if(v[i]!=b){
            cout << b << endl;
            break;
        }
        b++;
    }
}