#include <bits/stdc++.h>

using namespace std;


string solution(string s) {
    // TODO: Implement me!
    vector<char> vowels = {'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E', 'O'};
    string answer;
    for(char character : s){
        bool isVowel=false;
        for(char vowel : vowels){
            if(character == vowel){
                isVowel=true;
            }
        }
        if(!isVowel)answer.push_back(character);
    }
    return answer;
}
