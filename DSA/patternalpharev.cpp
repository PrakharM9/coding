#include<bits/stdc++.h>
using namespace std;
int main(){
    char ch='A',ch2='A';
    for(int i=0;i<5;i++){
        for(int j=5;j>=5-i;j--){
            cout<<ch;
            ch++;
        }
        ch=ch2;
        cout<<endl;
    }
    return 0;
}