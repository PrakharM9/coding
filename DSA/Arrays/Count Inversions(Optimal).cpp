#include <bits/stdc++.h>
using namespace std;
int merge(vector<int>&arr,int low,int mid,int high){
    int count=0;
    vector<int>temp;
    int left=low,right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            count+=(mid-left+1);
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
    return count;   
}
int mergesort(vector<int>&arr,int low,int high){
    int cnt=0;
    if(low>=high)return cnt;
    int mid=(low+high)/2;
    cnt+=mergesort(arr,low,mid);
    cnt+=mergesort(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}
int numberofinversion(vector<int>&arr,int n){
    return mergesort(arr,0,n-1);
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<"Total number of inversions are "<<numberofinversion(arr,n)<<endl;
  return 0;
}