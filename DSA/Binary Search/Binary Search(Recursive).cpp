#include <bits/stdc++.h>
using namespace std;
int binarysearch(vector<int>arr,int low,int high,int target){
    if(low>=high)return -1;
    int mid=(low+high)/2;
    if(arr[mid]==target)return mid;
    else if(arr[mid]>target)return binarysearch(arr,low,mid,target);
    return binarysearch(arr,mid+1,high,target);
}
int main()
{
  int n,target;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>target;
  int index=binarysearch(arr,0,n-1,target);
  if(index==-1){
    cout<<"Element not present";
  }
  else{
    cout<<"Element present at index "<<index<<endl;
  }
  return 0;
}