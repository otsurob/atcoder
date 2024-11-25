#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    set<int> st;
    cin>> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin>>a[i];
        st.insert(a[i]);
    }
    if(a.size()%3!=0){
        cout<<"No"<<endl;
        exit(1);
    }
    if (st.size()==3){
        if(st.find(0)!=st.end()){
            cout<<"No"<<endl;
            exit(1);
        }
        else{
            vector<int> b(10);
            int k=0;
            for(auto x : st){
                b[k]=x;
                k++;
            }
            for (int i=0; i<3; i++){
                // cout<<"a"<< endl;
                if((b[i%3]^b[(i+1)%3])!=b[(i+2)%3]){
                    // cout << b[i%3]<<b[(i+1)%3]<<b[(i+2)%3]<<(b[i%3]^b[(i+1)%3]);
                    cout << "No" << endl;
                    exit(1);
                }
            }
            for (int i=0; i<3; i++){
                if(count(a.begin(), a.end(), b[i])!=a.size()/3){
                    cout << "No" << endl;
                    exit(1);
                }
            }
        }

    }else if(st.size()==2){
        if(st.find(0)==st.end()){
            cout<<"No"<<endl;
            exit(1);
        }else{
            if(count(a.begin(), a.end(), 0)!=a.size()/3){
                cout<<"No"<<endl;
            }
        }
    }
    cout<<"Yes"<<endl;
}