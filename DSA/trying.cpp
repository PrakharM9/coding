#include<bits/stdc++.h>
void merege(int arr[],int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
using namespace std;
void mergesort(int arr[],int low,int high){
    if(low==high)return;
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merege(arr,low,mid,high);
}
int main(){
    int num;
    cin>>num;
    int array[num];
    for(int i=0;i<num;i++){
        cin>>array[i];
    }
    mergesort(array,0,num-1);
    for(int i=0;i<num;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}