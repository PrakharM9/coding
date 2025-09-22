#include <bits/stdc++.h>
using namespace std;
int countrotation(vector<int>arr){
    int low=0,high=arr.size()-1;
    int ans=INT_MAX;
    int index=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[high]){
            if(arr[low]<=ans){
                ans=min(arr[low],ans);
                index=low;
            }
            break;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                index=low;
                ans=arr[low];
            }
            low=mid+1;
        }
        else{
            if(arr[mid]<ans){
                index=mid;
                ans=arr[mid];
            }
            high=mid-1;
        }
    }
    return index;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<countrotation(arr);
  return 0;
}