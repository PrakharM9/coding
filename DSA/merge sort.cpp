#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr,int low,int mid,int high){
    vector<int>temp;
    int left=low,right=mid+1;
    while(low<=mid && right<=high){
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
void mergesort(vector<int>&arr,int low,int high){
    if(low==high)return;
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main()
{
  int num;
  cin>>num;
  vector<int>array(num);
  for(int i=0;i<num;i++){
    cin>>array[i];
  }
   mergesort(array,0,num-1);
   for(auto it:array){
    cout<<it<<" ";
   }
  return 0;
}