#include <bits/stdc++.h>
using namespace std;
int binarysearch(vector<int>arr,int n,int target){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target)return mid;
        else if(target>arr[mid])low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main()
{
  int n,k;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>k;
  int answer=binarysearch(arr,n,k);
  if(answer!=-1)cout<<"Index of "<<k<<" is "<<answer;
  else cout<<"Element is not present";
  return 0;
}