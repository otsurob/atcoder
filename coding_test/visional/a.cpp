#include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;


vector<string> eng_num = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nighteen"},
eng_under_hundred = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred"},
eng_unit = {"", "thousand", "million", "billion"};

string under_thousand(int num){
    if(num==0)return "";
    string res="";
    int ind;
    if(num/100!=0){
        res+=eng_num[num/100];
        res+=" hundred ";
        num%=100;
    }
    if(num<20){
        if(num==0)return res + ' ';
        else{
            res+=eng_num[num];
            return res + ' ';
        }
    }else{
        res+=eng_under_hundred[num/10];
        res+=' ';
        if(num%10==0)return res;
        else{
            res+=eng_num[num%10];
            res+=' ';
            return res;
        }
    }
}

int main(int argc, char *argv[]) {

    string number;
    cin>>number;

    string answer="";


    bool isPeriodExited = false;
    int periodLocation = 0;
    // ピリオドの存在・位置を調べる
    for(int i=0; i<number.length(); i++){
        if(number[i]=='.'){
        if(!isPeriodExited){
            periodLocation=i;
            isPeriodExited=true;
        }else{
            // ピリオドが複数あるのは入力に反する
            cout<<-1<<endl;
            return 0;
        }
        }else{
            if(number[i]>'9' or number[i]<'0'){
                cout<<-1<<endl;
                return 0;
            }
        }
    }

    // 整数部と小数部を分割
    string intger_number, decimal_number;
    if(isPeriodExited){
        intger_number=number.substr(0, periodLocation);
        decimal_number = number.substr(periodLocation, number.length()-periodLocation);
    }else{
        intger_number=number;
    }

    // 整数部の変換
    if(intger_number=="0"){
        answer="zero ";
            if(isPeriodExited){
            // answer.pop_back();
            answer+="point";
            for(char one_number : decimal_number){
                answer += eng_num[one_number-'0'];
                answer+=' ';
            }
        }
        answer.pop_back();

        answer[0] = answer[0]-32;
        cout<<answer<<endl;
        return 0;
    }
    string tmp_string = "";
    vector<string> unit_block;
    for(int i=0; i<intger_number.length(); i++){
        tmp_string = intger_number[intger_number.length()-1-i] + tmp_string;
        if(i%3==2){
            unit_block.push_back(tmp_string);
            tmp_string="";
        }
    }

    if(tmp_string!="")unit_block.push_back(tmp_string);
    
    // string answer;
    for(int i=0; i<unit_block.size(); i++){
        if(under_thousand(stoi(unit_block[i]))=="")continue;
        answer=under_thousand(stoi(unit_block[i]))+eng_unit[i] + ' ' + answer;
    }

    if(isPeriodExited){
        answer.pop_back();
        answer+="point";
        for(char one_number : decimal_number){
            answer += eng_num[one_number-'0'];
            answer+=' ';
        }
    }
    answer.pop_back();

    answer[0] = answer[0]-32;
    cout<<answer<<endl;

  return 0;
}
