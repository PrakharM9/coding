#include <bits/stdc++.h>
using namespace std;
int main(){
    char ch='A';
    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            cout<<ch;
        }
        ch++;
        cout<<endl;
    }
}