#include <bits/stdc++.h>
using namespace std;
int ceil(vector<int>arr,int target){
    int n=arr.size();
    int low=0,high=n-1;
    int res=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
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
  int result=ceil(arr,target);
  if(result<n){
    cout<<"Ceil of "<<target<<" is "<<arr[result]<<endl;
  }
  else{
    cout<<"Ceil of element is not present";
  }
  return 0;
}