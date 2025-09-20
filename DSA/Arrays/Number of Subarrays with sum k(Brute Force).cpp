#include <bits/stdc++.h>
using namespace std;
int countsubarr(vector<int>arr,int k){
  int count=0;
  for(int i=0;i<arr.size();i++){
    for(int j=i;j<arr.size();j++){
      int sum=0;
      for(int k=i;k<=j;k++){
        sum+=arr[k];
      }
      if(sum==k)count++;
    }
  }
  return count;
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
  cout<<"Total subarrays are "<<countsubarr(arr,target);
  return 0;
}