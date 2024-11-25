#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int flag=0;
    cin>>s;
    int n = s.length();
    if(s[0]>='A' && s[0]<='Z'){
        for (int i=1; i<n; i++){
            if(s[i]<'a' || s[i]>'z'){
                flag=1;
            }
        }
        if (flag==0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }else{
        cout<<"No"<<endl;
    }
}