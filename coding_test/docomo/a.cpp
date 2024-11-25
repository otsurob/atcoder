#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  map<char, string> morse;

  morse['a'] = ".-";
  morse['b'] = "-...";
  morse['c'] = "-.-.";
  morse['d'] = "-..";
  morse['e'] = ".";
  morse['f'] = "..-.";
  morse['g'] = "--.";
  morse['h'] = "....";
  morse['i'] = "..";
  morse['j'] = ".---";
  morse['k'] = "-.-";
  morse['l'] = ".-..";
  morse['m'] = "--";
  morse['n'] = "-.";
  morse['o'] = "---";
  morse['p'] = ".--.";
  morse['q'] = "--.-";
  morse['r'] = ".-.";
  morse['s'] = "...";
  morse['t'] = "-";
  morse['u'] = "..-";
  morse['v'] = "...-";
  morse['w'] = ".--";
  morse['x'] = "-..-";
  morse['y'] = "-.--";
  morse['z'] = "--..";


    ifstream ifs("dictionary.txt");
    string str;
    while(ifs){
        ifs>>str;
        for(int i=0; i<str.length(); i++){
            if(str[i]<'a')str[i]+=32;
        }
        string code="";
        for(int i=0; i<str.length(); i++){
          code += morse[str[i]];
        }
        if(s==code){
          cout<<str<<endl;
          break;
        }
    }
    ifs.close();
  return 0;
}
