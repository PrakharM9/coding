#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin>>num;
    string temp,array[num];
    for(int i=0;i<num;i++){
        cin>>array[i];
    }
    cout<<"Initial order: ";
    for(int i=0;i<num;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<=num-1;i++){
        int j=i;
        while(j>0 && array[j-1]>array[j]){
            temp=array[j-1];
            array[j-1]=array[j];
            array[j]=temp;
            j--;
        }
        
        if(i>0){
            cout<<"After Iteration "<<i<<": ";
            for(int k=0;k<num;k++){
                cout<<array[k]<<" ";
            }
            cout<<endl;
        }
        
    }
    cout<<"Sorted order: ";
    for(int i=0;i<num;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}

