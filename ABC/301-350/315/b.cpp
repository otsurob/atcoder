#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, a, count=0;
    vector<int> v;
    cin>>m;
    for (int i=0; i<m; i++){
        cin>>a;
        v.push_back(a);
        count += a;
    }
    int mid = (count/2)+1;
    // cout << mid << " " << count << endl;
    for (int i=0; i<m; i++){
        mid -= v[i];
        // cout << count << endl;
        if(mid<=0){
            cout << i+1 << " " << mid+v[i] << endl;
            break;
        }
    }
}