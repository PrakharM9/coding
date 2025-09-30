// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,temp,condition=1,count=0,index=0;
    cin>>num;
    int array[num];
    int array2[num];
    for(int i=0;i<num;i++){
        cin>>array[i];
    }
    //change 1
    for(int i=0;i<num-1;i++){
        for(int j=0;j<num-i-1;j++){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    for(int i=0;i<num;i++){
        temp=array[i];
        for(int j=0;j<index;j++){
            //change 2
            if(array2[j]==temp){
                condition=0;
            }
        }
        if(condition==1){
            array2[index]=temp;
            index++;
            for(int k=0;k<num;k++){
                if(array[k]==temp){
                    count++;
                }
            }
            //change 3
            cout<<temp<<" - "<<count;
            if(count==1){
                cout<<" time"<<endl;
            }
            else{
                cout<<" times"<<endl;
            }
        }
        count=0;
        condition=1;
    }
    return 0;
}