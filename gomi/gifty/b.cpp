#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void english_word_method(string s){
    vector<string> ret_vector;
    map<string, int> count;
    vector<string> word;
    string now="";
    s+=' ';
    for(char c : s){
        if(c!=' ')now+=c;
        else{
            if(count[now]==0){
                count[now]=1;
                word.push_back(now);
            }else{
                count[now]++;
            }
            now="";
        }
    }
    for(string t : word){
        cout<<t<<':'<<count[t]<<endl;
    }
}


int main(void){
    // Your code here!
    string input_text;
    getline(cin, input_text);
    english_word_method(input_text);
}

