#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    for (int i=0; i<s.size(); i++){

        // if (s[i]=="a"||s[i]=="u"||s[i]=="i"||s[i]=="e"||s[i]=="o"){
        if (s[i]=='a'||s[i]=='u'||s[i]=='i'||s[i]=='e'||s[i]=='o'){
            continue;
        }
        cout << s[i];
    }
    cout << endl;
}