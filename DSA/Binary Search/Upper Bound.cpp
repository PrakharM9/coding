#include <bits/stdc++.h>
using namespace std;
int upperbound(vector<int>arr,int element){
    int n=arr.size();
    int low=0,high=n-1;
    int answer=n;
    while(low<=high){
        int mid=(low+high)/2;
        // Might be answer
        if(arr[mid]>element){
            answer=mid;
            // checking for smaller index that can satisfy the condition
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return answer;
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
  int result=upperbound(arr,target);
  if(result<n){
    cout<<"Upper Bound of "<<target<<" is "<<arr[result];
  }
  else cout<<"Upper Bound not present";
  return 0;
}