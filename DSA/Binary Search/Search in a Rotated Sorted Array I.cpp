#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>arr,int target){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target)return true;
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                high=mid-1;
            }
            else low=mid+1;
        }
        else{
            if(arr[mid]<=target && target<=arr[high])low=mid+1;
            else low=mid-1;
        }
    }
    return false;
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
  if(check(arr,target)){
    cout<<"Element is present";
  }
  else cout<<"Element is not present";
  return 0;
}