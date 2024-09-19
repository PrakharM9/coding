#include<bits/stdc++.h>
using namespace std;
int main(){
    int num=1;
    for(int i=0;i<5;i++){
        if(i%2!=0){
            num=0;
        }
        else{
            num=1;
        }
        for(int j=0;j<=i;j++){
            cout<<num<<" ";
            if(num==1){
                num=0;
            }
            else{
                num=1;
            }
        }
        cout<<endl;
    }
    return 0;
}