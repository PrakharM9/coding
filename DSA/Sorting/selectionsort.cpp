#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,min,index,temp ;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    cout<<"Student's height order before sorting: ";
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<num-1;i++){
        min=arr[i];
        index=i;
        for(int j=i;j<num;j++){
            if(arr[j]<min){
                if(arr[j]<min){
                    min=arr[j];
                    index=j;
                }
            }
        }
        temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
        cout<<"Height order of students after iteration "<<i+1<<" :";
        for(int k=0;k<num;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
    cout<<"After final comparision of all elements, the height order becomes: ";
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}