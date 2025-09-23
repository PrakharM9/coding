#include <bits/stdc++.h>
using namespace std;
int pattern(int n){
    for(int i=0;i<n;i++){
        for(int j=n-i;j>0;j--){
            cout<<"*";
        }
        for(int j=2*i;j>0;j--){
            cout<<" ";
        }
        for(int j=n-i;j>0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        for(int j=(2*(n-1))-(2*i);j>0;j--){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
    int num;
    cin>>num;
    pattern(num);
    return 0;
}