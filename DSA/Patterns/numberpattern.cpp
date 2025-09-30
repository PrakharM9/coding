#include <bits/stdc++.h>
using namespace std;
int main(){
    int num=1,num2=1;
    int num3;
    for(int i=0;i<4;i++){
        for(int j=0;j<=i;j++){
            cout<<num;
            num++;
        }
        for(int j=6-(2*i);j>0;j--){
            cout<<" ";
        }
        num3=i+1;
        for(int j=0;j<=i;j++){
            cout<<num3;
            num3--;
        }
        num=num2;
        cout<<endl;
    }
    return 0;
}