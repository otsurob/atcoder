#include <bits/stdc++.h>
using namespace std;

vector<bool> solution(vector<int> allowances, int extraAllowances) {
    // TODO: Implement me!
    vector<bool> answer;
    int max_num = -1;
    for(int x : allowances){
        max_num = max(max_num, x);
    }
    for(int x : allowances){
        if(max_num<=x+extraAllowances)answer.push_back(true);
        else answer.push_back(false);
    }
    return answer;
}