#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a, b, ans;
    cin >> n >> m;
    vector<int> v(n, 1);
    for(int i=0; i<m; i++){ 
        cin >> a >> b;
        v.at(b-1)=0;
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += v.at(i);
        if(v.at(i)==1){
            ans = i+1;
        }
    }
    if(sum==1){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
    // for(int i=0; i<m; i++) cout << w.at(i).at(0) << endl;

}