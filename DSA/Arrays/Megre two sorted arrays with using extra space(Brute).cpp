#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr1,vector<int>&arr2){
    int n=arr1.size();
    int m=arr2.size();
    vector<int>arr(n+m);
    int left=0,right=0,index=0;
    while(left<n && right<m){
        if(arr1[left]<=arr2[right]){
            arr[index++]=arr1[left++];
        }
        else{
            arr[index++]=arr2[right++];
        }
    }
    while(left<n) arr[index++]=arr1[left++];
    while(right<m) arr[index++]=arr2[right++];
    for(int i=0;i<n+m;i++){
        if(i<n)arr1[i]=arr[i];
        else arr2[i-n]=arr[i];
    }
}
int main()
{
    // In this code we are going to use extra space in order to merge and distribute elements
  int n,m;
  cin>>n;
  vector<int>arr1(n);
  for(int i=0;i<n;i++){
    cin>>arr1[i];
  }
  cin>>m;
  vector<int>arr2(m);
  for(int i=0;i<m;i++){
    cin>>arr2[i];
  }
  merge(arr1,arr2);
  for(auto it:arr1){
    cout<<it<<" ";
  }
  cout<<endl;
  for(auto it:arr2){
    cout<<it<<" ";
  }
  cout<<endl;
  return 0;
}