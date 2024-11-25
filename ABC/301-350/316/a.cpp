#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, h, x;
    cin >> n >> h >> x;
    vector<int>p(n);
    for (int i=0; i<n; i++){
        cin >> p[i];
    }
    for (int j=0; j<n; j++){
        if(p[j]>=x-h){
            cout << j+1;
            break;
        }
    }
}