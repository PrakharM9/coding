#include <bits/stdc++.h>
using namespace std;
int minimum(vector<int>arr){
    int n=arr.size(),ans=INT_MAX;
    int low=0,high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[high]){
            ans=min(ans,arr[low]);
            break;
        }
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else{
            ans=min(ans,arr[mid]);
            high=n-1;
        }
    }
    return ans;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<minimum(arr);
  return 0;
}