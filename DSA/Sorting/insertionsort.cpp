#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin>>num;
    int array[num];
    for(int i=0;i<num;i++){
        cin>>array[i];
    }
    for(int i=0;i<num;i++){
        int j=i;
        while(j>0 && array[j-1]>array[j]){
            if(array[j-1]>array[j]){
                int temp=array[j-1];
                array[j-1]=array[j];
                array[j]=temp;
            }
            j--;
        }
    }
    for(int i=0;i<num;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}

