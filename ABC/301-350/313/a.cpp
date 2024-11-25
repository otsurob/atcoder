#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    int m=0;
    for (int j=1; j<N; j++){
        m=max(m, A[j]);
    }
    cout << max(0, m - A[0]+1) << endl;
    

}