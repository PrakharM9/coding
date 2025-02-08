// You are using GCC
#include<bits/stdc++.h>
using namespace std;
long long powercalc(int values,int powers){
    if(powers==0){
        return 1;
    }
    return values*powercalc(values,powers-1);
}
int main(){
    int num;
    cin>>num;
    int values[num];
    int power[num];
    for(int i=0;i<num;i++){
        cin>>values[i];
        cin>>power[i];
    }
    for(int i=0;i<num;i++){
        if(power[i]==0){
            cout<<1<<endl;
        }
        else{
            cout<<powercalc(values[i],power[i])<<endl;
        }
    }
    return 0;
}