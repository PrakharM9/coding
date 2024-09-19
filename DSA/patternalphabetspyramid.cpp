#include <bits/stdc++.h>
using namespace std;
int main(){
    char ch='A';
    char ch2='A';
    for(int i=0;i<4;i++){
        for(int j=2-i;j>=0;j--){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<ch;
            ch++;
        }
        ch2+=i-1;
        for(int j=0;j<i;j++){
            cout<<ch2;
            ch2--;
        }
        for(int j=2-i;j>=0;j--){
            cout<<" ";
        }
        cout<<endl;
        ch='A';
        ch2='A';
    }
    return 0;
}