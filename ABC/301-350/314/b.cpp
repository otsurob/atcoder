#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, c, x, mn=1000;
    vector<int> ans, ans2;
    vector<vector<int>> aa;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> c;
        vector<int> a(c);
        for (int j=0; j<c; j++) cin >> a[j];
        aa.push_back(a);
    }
    cin >> x;
    // cout << aa[1][1] << endl;
    for (int i=0; i<n; i++){
        for (int y : aa[i]){
            // cout << y << " ";
            if(y==x){
                ans.push_back(i);
            }
        }
        // cout << endl;
    }
    for (int k : ans){
        // cout << k << endl;
        // for (int l : aa[k]) cout << l << " ";
        int s = aa[k].size();
        // cout << s << endl;
        mn = min(mn, s);
    }
    // cout << mn << endl;
    for (int k : ans){
        int s = aa[k].size();
        if (aa[k].size()==mn){
            ans2.push_back(k);
        }
    }
    cout << ans2.size() << endl;
    for (int l : ans2) cout << l+1 << " ";
    cout << endl;
}