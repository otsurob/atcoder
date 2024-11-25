#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int mx=0, mn;
    cin>>s;
    vector<int> a(26, 0);
    int n=s.length();
    // char c = 'a';
    // int i=int(c)-97;
    // cout<<i<<endl;
    for (int i=0; i<n; i++){
        int m = int(s[i])-97;
        a[m]++;
    }
    for (int i=0; i<26; i++){
        if(mx<a[i]){
            mn=i;
            mx=a[i];
        }
    }
    char c = mn+97;
    cout<<c<<endl;
}