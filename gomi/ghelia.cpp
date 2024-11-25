#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
  ll w, h, b;
  cin>>w>>h>>b;
  ll bmi;
  rep(i, 101){
    bmi=10000*(w-i)/(h*h);
    if(10000*(w-i)%(h*h)!=0) bmi++;
    if(bmi<=b){
      cout<<i<<endl;
      return 0;
    }
  }
}