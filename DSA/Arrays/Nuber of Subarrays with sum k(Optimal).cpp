#include <bits/stdc++.h>
using namespace std;
int countsubarr(vector<int>arr,int k){
    int count=0,n=arr.size(),presum=0;
    unordered_map<int,int>mpp;
    mpp[0]++;
    for(int i=0;i<n;i++){
        presum+=arr[i];
        count+=mpp[presum-k];
        mpp[presum]++;
    }
    return count;
}
int main(){
  int n,target;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>target;
  cout<<"Count of Subarrays is "<<countsubarr(arr,target);
  return 0;
}