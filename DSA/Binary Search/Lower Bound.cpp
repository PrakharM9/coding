#include <bits/stdc++.h>
using namespace std;
int lower_bound(vector<int>arr,int target){
    int n=arr.size();
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
// In lower bound we return the index of the element greater than or equal to target 
int main()
{
  int n,target;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>target;
  int index=lower_bound(arr,target);
  if(index<n){
    cout<<"Index is "<<index;
  }
  else{
    cout<<"Lower Bound not present";
  }
  return 0;
}