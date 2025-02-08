#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,min,index;
    cin>>num;
    int array[num];
    for(int i=0;i<num;i++){
        cin>>array[i];
    }
    for(int i=0;i<num-1;i++){
        min=array[i];
        index=i;
        for(int j=i+1;j<num;j++){
            if(array[j]<min){
                min=array[j];
                index=j;
            }
        }
        swap(array[i],array[index]);

    }
    for(int i=0;i<num;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}

