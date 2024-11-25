#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a;
    string s;
    vector<int> c;
    // vector<string> ans;
    cin>>n>>m;
    cin>>s;
    // cout << s << endl;
    vector<int> t(m, 0);
    vector<string> vs(m);
    vector<string> vs2(m);
    for (int i=0; i<n; i++){
        cin>>a;
        c.push_back(a-1);
    }
    // cout << s[0] << endl;
    for (int i=0; i<n; i++){
        vs[c[i]].push_back(s[i]);
    }
    // cout << 'b' << endl;
    for (int i=0; i<m; i++){
        // cout << vs[i] << endl;
        vs2[i].push_back(vs[i][vs[i].size()-1]);
        // cout << vs2[i] << endl;
        vs2[i]+=vs[i];
        // cout << vs2[i] << endl;
    }
    // cout << 'c' << endl;
    for (int x : c){
        // ans.push_back(vs[x][t[x]]);
        cout << vs2[x][t[x]];
        t[x]++;
    }
    cout << endl;
}